# FreeRTOS-ESP-IDF-SPI
1 - ESP32 - Scope:<br> 
    &emsp;&nbsp;&nbsp;VSPI_initiation.c file Master SPI (VSPI) initiation is implemented.
    
2 - ESP32 - ESP32 (Master as transmitter):<br> 
    &emsp;&nbsp;&nbsp;Master_transmitter_output.c file sends "A" character to the slave,<br> 
    &emsp;&nbsp;&nbsp;Slave_receiver_input.c file receives "A" from a master.
    
3 - ESP32 - ESP32 (Master as receiver):<br> 
    &emsp;&nbsp;&nbsp;Master_receiver.c file receives a string from the slave,<br> 
    &emsp;&nbsp;&nbsp;Slave_transmitter.c file sends a string to the master.

4 - ESP32 - Raspberry Pi 5 (Master as receiver):<br> 
    &emsp;&nbsp;&nbsp;SPI ESP32 Slave transmit.c file sends a hexadecimal value<br> 
    &emsp;&nbsp;&nbsp;SPI Raspberry Pi 5 Master receive.py file receives a hexadecimal value

5 - STM32 - Raspberry Pi 5 (Master as receiver):<br> 
    &emsp;&nbsp;&nbsp;SPI STM32 Slave transmit.c file sends a hexadecimal value<br> 
    &emsp;&nbsp;&nbsp;SPI Raspberry Pi 5 Master receive.py file receives a hexadecimal value

