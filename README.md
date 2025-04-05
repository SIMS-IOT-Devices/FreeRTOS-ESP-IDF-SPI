# FreeRTOS-ESP-IDF-SPI
1 - ESP32 - Scope:<br> 
    &emsp;&nbsp;&nbsp;1 - VSPI_initiation.c file Master SPI (VSPI) initiation is implemented.
    
2 - ESP32 - ESP32 (Master as transmitter):<br> 
    &emsp;&nbsp;&nbsp;2 - Master_transmitter_output.c file sends "A" character to the slave,<br> 
    &emsp;&nbsp;&nbsp;2 - Slave_receiver_input.c file receives "A" from a master.
    
3 - ESP32 - ESP32 (Master as receiver):<br> 
    &emsp;&nbsp;&nbsp;Master_receiver.c file receives a string from the slave,<br> 
    &emsp;&nbsp;&nbsp;Slave_transmitter.c file sends a string to the master.

4 - ESP32 - Raspberry Pi 5 (Master as receiver):<br> 
    &emsp;&nbsp;&nbsp;4 - SPI ESP32 Slave transmit.c file sends a hexadecimal value<br> 
    &emsp;&nbsp;&nbsp;4 - SPI Raspberry Pi 5 Master receive.py file receives a hexadecimal value

5 - STM32 - Raspberry Pi 5 (Master as receiver):<br> 
    &emsp;&nbsp;&nbsp;5 - SPI_STM32_Slave_main.c file sends a hexadecimal value<br> 
    &emsp;&nbsp;&nbsp;5 - SPI_RP5_Master.py file receives a hexadecimal value

