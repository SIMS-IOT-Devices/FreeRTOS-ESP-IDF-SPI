# FreeRTOS-ESP-IDF-SPI
1 - ESP32 - Scope:<br> 
    &emsp;&nbsp;&nbsp;In VSPI_initiation.c file Master SPI (VSPI) initiation is implemented.
    
2 - ESP32 - ESP32 (Master as transmitter):<br> 
    &emsp;&nbsp;&nbsp;The Master_transmitter_output.c file sends "A" character to the slave,<br> 
    &emsp;&nbsp;&nbsp;and the Slave_receiver_input.c file receives "A" from a master.
    
3 - ESP32 - ESP32 (Master as receiver):<br> 
    &emsp;&nbsp;&nbsp;The Master_receiver.c file receives a string from the slave,<br> 
    &emsp;&nbsp;&nbsp;and the Slave_transmitter.c file sends a string to the master.
