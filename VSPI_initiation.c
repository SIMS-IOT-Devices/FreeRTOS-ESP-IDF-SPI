// Master SPI (VSPI) initiation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

static const char TAG[] = "VSPI";

void app_main(void)
{
    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1000000, // Clock out at 1 MHz with 1 us cycle
        .mode = 0,                 // SPI mode 0 - the clock signal starts with a low signal
        .spics_io_num = 15,        // CS pin
        .queue_size = 7,           // Queue 7 transactions at a time
    };

    ESP_LOGI(TAG, "Initializing VSPI"); // SPI3 = VSPI
    spi_bus_config_t buscfg = {
        .miso_io_num = 12,
        .mosi_io_num = 13,
        .sclk_io_num = 14,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 32,
    };

    // Initialize the SPI
    spi_bus_initialize(VSPI_HOST, &buscfg, 1);

    // Define SPI handle
    spi_device_handle_t spi;
    spi_bus_add_device(VSPI_HOST, &devcfg, &spi);
 
    // SPI transaction structure
    spi_transaction_t trans;
    memset(&trans, 0, sizeof(trans));
    trans.length = 20;              // length in bits
    const char test_str[] = "A";    // ASCII A, Hex 41, Binary 01000001
    trans.tx_buffer = test_str;     // pointer to data to be transmitted
    ESP_LOGI(TAG, "Write via VSPI: %s", test_str);

    while (1)
    {
        spi_device_transmit(spi, &trans);
        vTaskDelay(1);              // Every 10 ms
    }
}
