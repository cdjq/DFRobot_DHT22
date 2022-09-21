/*!
 * @file DFRobot_DHT22.h
 * @brief This is a temperature & humidity sensorlibrary  
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [PengKaixing]kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date 2022-9-7
 * @url https://github.com/DFRobot/DFRobot_DHT22
 */
#ifndef _DHT22_H_
#define _DHT22_H_

#include <inttypes.h>
#include <Arduino.h>
#include <pins_arduino.h>
extern "C" {
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
}
#define DIRECT_READ(base, mask)		(((*(base)) & (mask)) ? 1 : 0)
#define DIRECT_MODE_INPUT(base, mask)	((*(base+1)) &= ~(mask))
#define DIRECT_MODE_OUTPUT(base, mask)	((*(base+1)) |= (mask))
#define DIRECT_WRITE_LOW(base, mask)	((*(base+2)) &= ~(mask))
//#define DIRECT_WRITE_HIGH(base, mask)	((*(base+2)) |= (mask))

// This should be 40, but the sensor is adding an extra bit at the start
#define DHT22_DATA_BIT_COUNT 41

#define DHT22_ERROR_VALUE -995

class DFRobot_DHT22
{
public:
  /**
   * @struct DHT22_ERROR_t
   * @brief ENUM for error functions
   */
  typedef enum
  {
    DHT_ERROR_NONE = 0,
    DHT_BUS_HUNG,
    DHT_ERROR_NOT_PRESENT,
    DHT_ERROR_ACK_TOO_LONG,
    DHT_ERROR_SYNC_TIMEOUT,
    DHT_ERROR_DATA_TIMEOUT,
    DHT_ERROR_CHECKSUM,
    DHT_ERROR_TOOQUICK
  } DHT22_ERROR_t;
  
  DFRobot_DHT22(uint8_t pin);

  /**
   * @fn readData
   * @brief Get sensor data 
   * @return DHT22_ERROR_t type, return error type 
   * @ DHT_ERROR_NONE
   * @ DHT_BUS_HUNG
   * @ DHT_ERROR_NOT_PRESENT
   * @ DHT_ERROR_ACK_TOO_LONG
   * @ DHT_ERROR_SYNC_TIMEOUT
   * @ DHT_ERROR_DATA_TIMEOUT
   * @ DHT_ERROR_CHECKSUM
   * @ DHT_ERROR_TOOQUICK
   */
  DHT22_ERROR_t readData(void);

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
#if !defined(DHT22_NO_FLOAT)
  /**
   * @fn getHumidity
   * @brief Get sensor humidity 
   * @return  float type, return sensor humidity 
   */
  float getHumidity(void);

  /**
   * @fn getTemperatureC
   * @brief Get sensor temperature(Celsius)
   * @return  float type, return sensor temperature 
   */
  float getTemperatureC(void);

  /**
   * @fn getTemperatureF
   * @brief Get sensor temperature(Fahrenheit) 
   * @return  float type, return sensor temperature 
   */
  float getTemperatureF(void);
#endif
private:
  uint8_t _bitmask;
  volatile uint8_t *_baseReg;
  unsigned long _lastReadTime;
  short int _lastHumidity;
  short int _lastTemperature;
};

#endif /*_DHT22_H_*/
