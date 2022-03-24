# BE Hydroponics
Set your house ambience with respect to the ambient temperature using a temperature sensor and WS281B Addressable LEDs in 5 steps

## Pre-requisites

* **Hardware**
  + Arduino Uno or any other equivalent board
  + NodeMCU ESP8266
  + 5v Power supply
  + 3 Male-to-female Jumper Cables
  + DHT11 or newer temperature sensor
  + Breadboard (Optional)

* **Software**
  + [Arduino IDE](https://www.arduino.cc/en/software "Download Arduino IDE")
  + Library : FastLED *(not by AdaFruit)* & Unified Sensor by AdaFruit *[howTo](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)* & DHT

## Usage

  Step 1 : Open main.ino on your Arduino IDE\
  Step 2 : Install FastLED & Unified Sensors by AdaFruit\
  Step 3 : Enter the number of LEDs on your strip on the 4th line (*Change data pins according to your prefrence if needed*)\
  Step 4 : Select the right Com port via Tools\
  Step 5 : Make the right connections *(Check figure below)*\
  Step 5 : Hit Upload
  
  #### Note : Disconnect the power supply jumper cable to LED & Sensor to avoid any unwanted issues

  ![Connections](https://github.com/Pranav941/be-hydroponics/blob/main/figures/BE-Hydroponics.png?raw=true)
