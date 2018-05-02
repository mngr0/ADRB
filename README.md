# ADRB
Adhesive Dispenser Raspberry Bridge

# description
I control an adhesive dispencer with a MCU, and I have a RPi that will manage any interface for the MCU:
  
  -Bluetooth (interfacing with ADAI)
  
  -Graphical (interfacing with ADRI)
  
so, this sfotware will be a daemon that receive messages from BT or other programs, and translate them in SPI for the MCU  
