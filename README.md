# DFRobot_DHT22
- [中文版](./README_CN.md)

DHT22 is a temperature & humidity sensor with calibration of digital signal output. It utilizes exclusive digital-signal-collecting-technique and humidty sensing technology that ensures the reliability and lon-term stability of the product.  

The sensor includes a capacitive sensing element and an NTC temperature sensing element, which is connected to a high-performance 8bits microcontroller. Thus, the product features high quality, fast response, anti-interference ability, cost-effective advantages, etc. 
Its single-wire serial interface makes the system integration simple and quick. With ultra-small size, low power consumption and up to 20m transmisstion distance, this sensor is ideal for various applications. Directly plug it onto the Arduino expansion shield, then you are ready to go. 

DHT22 has relatively high accuracy, which can be a replace of the SHT10 sensor. It gives excellent performance in projects with high measuring requirement of temperature and humdity. Combing it with the Arduino expansion board to realize more interactive effects. 

![Product Image](./resources/images/SEN0137.png)


## Product Link (https://www.dfrobot.com/product-1102.html)

    SKU: SEN0137

## Table of Contents

  * [Summary](#summary)
  * [Installation](#installation)
  * [Methods](#methods)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Credits](#credits)

## Summary

This is a library for obtaining ambient temperature and humidity.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  /**
   * @fn getHumidityInt
   * @brief Get sensor humidity 
   * @return  short int type, return sensor humidity
   */
  short int getHumidityInt(void);

  /**
   * @fn getTemperatureCInt
   * @brief Get sensor temperature 
   * @return  short int type, return sensor temperature 
   */
  short int getTemperatureCInt(void);

  /**
   * @fn clockReset
   * @brief Reset clock global variable  
   */
  void clockReset(void);

  /**
   * @fn getHumidity
   * @brief Get sensor humidity 
   * @return  float type, return sensor humidity 
   */
  float getHumidity(void);

  /**
   * @fn getTemperatureC
   * @brief Get sensor temperature(Celcius)
   * @return  float type, return sensor temperature
   */
  float getTemperatureC(void);

  /**
   * @fn getTemperatureF
   * @brief Get sensor tempterature(Fahrenheit )
   * @return  float type, return sensor temperature 
   */
  float getTemperatureF(void);

```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32           |      √       |              |             | 
micro:bit        |      √       |              |             | 
ESP8266           |      √       |              |             | 

## History

- 2022/9/7 - Version 1.0.0 released.

## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2022. (Welcome to our [website](https://www.dfrobot.com/))





