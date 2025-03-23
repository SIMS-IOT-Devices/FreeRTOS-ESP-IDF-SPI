import spidev

# Create an SPI instance
spi = spidev.SpiDev()
spi.open(0, 0)  # Bus 0, Device 0 (CE0)
spi.max_speed_hz = 500000  # Set speed (adjust as needed)
spi.mode = 0  # SPI mode (0-3)

# Send triger
response = spi.xfer2([0x01])
print("Received:", hex(response[0]))

# Close SPI
spi.close()
