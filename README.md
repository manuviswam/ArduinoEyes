# ArduinoEyes
Display eyeball movement in SSD1306 OLED display with Arduino using SPI protocol

# Components used
- Arduino Uno
- GM009605B 0.96" OLED 128x64 pixel display using SSD1306 chip

This display comes with 4 pin SPI protocol which doesn't have ACK pin. So normal Adafruit library will not work. You can find library without ACK pin at https://bintray.com/olikraus/u8glib/Arduino/

# Connection diagram
![alt tag](https://raw.githubusercontent.com/manuviswam/arduinoeyes/master/connection_diagram.png)
