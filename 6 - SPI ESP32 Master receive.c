// Master as a receiver for SPI communication

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "lwip/igmp.h"

#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "soc/rtc_periph.h"
#include "driver/spi_master.h"
#include "esp_log.h"
// #include "esp_spi_flash.h"
#include "spi_flash_mmap.h"

#include "driver/gpio.h"
#include "esp_intr_alloc.h"

// Pins in use
#define GPIO_MOSI 12
#define GPIO_MISO 13
#define GPIO_SCLK 15
#define GPIO_CS 14

#define TAG "SPI"

// Main application
void app_main(void)
{
    esp_err_t ret;

    // Configuration for the SPI bus
    spi_bus_config_t buscfg = {
        .mosi_io_num = GPIO_MOSI,
        .miso_io_num = GPIO_MISO,
        .sclk_io_num = GPIO_SCLK,
        .max_transfer_sz = 8,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1};

    // Configuration for the SPI device on the other side of the bus
    spi_device_interface_config_t devcfg = {
        .command_bits = 0,
        .address_bits = 0,
        .dummy_bits = 0,
        .clock_speed_hz = 1000000, // 1 MHz
        .duty_cycle_pos = 128,      // 50% duty cycle
        .mode = 0,               // SPI mode 0
        .spics_io_num = GPIO_CS, // CS pin
        .cs_ena_posttrans = 3,      // Keep the CS low 3 cycles after transaction
        .queue_size = 1};

    // Initialize the SPI bus
    ret = spi_bus_initialize(HSPI_HOST, &buscfg, SPI_DMA_CH_AUTO);
    printf("spi_bus_initialize %d\n", ret); // ESP_OK = 0

    spi_device_handle_t spi_handle;
    ret = spi_bus_add_device(HSPI_HOST, &devcfg, &spi_handle);
    printf("spi_bus_add_device %d\n", ret); // ESP_OK = 0

    // uint8_t tx_data[] = {0xcc};
    // uint8_t rx_data[] = {0xdd};
    uint8_t tx_data = 'C';
    uint8_t rx_data = 'D';

    // printf("tx_data: 0x%02X\n", tx_data[0]);
    // printf("rx_data: 0x%02X\n", rx_data[0]);
    printf("tx_data: %c\n", tx_data);
    printf("rx_data: %c\n", rx_data);

    spi_transaction_t t = {
        // .length = 8 * sizeof(tx_data),              // length in bits
        .length = 8 * sizeof(tx_data),         // bits to transmit
        .rxlength = 8 * sizeof(tx_data),       // bits to receive
        // .tx_buffer = tx_data,
        // .rx_buffer = rx_data
        .tx_buffer = &tx_data,
        .rx_buffer = &rx_data
    };

    printf("Master received:\n");
    while (1)
    {
        ret = spi_device_transmit(spi_handle, &t);
        printf("\nspi_device_transmit %d\n", ret); // ESP_OK = 0

        // printf("Transmited: 0x%02X\n", tx_data[0]);
        // printf("Received: 0x%02X\n", rx_data[0]);
        printf("Transmited data: %c\n", tx_data);
        printf("Received data: %c\n", rx_data);
        printf("Transmited: %c\n", *((char *)t.tx_buffer));
        printf("Received: %c\n", *((char *)t.rx_buffer));

        vTaskDelay(pdMS_TO_TICKS(5000)); // Delay 1 second
    }
}
