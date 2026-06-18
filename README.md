# DFRobot_N20Motor

===========================

* [中文版](./README_CN.md)

The N20 DC motor driver library provides dual PWM pin control for N20 micro DC motors, supporting speed control, direction control and coast stop functions.

![product image]

## Product Link (https://www.dfrobot.com)
    SKU: DFR1276

## Table of Contents

  * [Summary](#summary)
  * [Installation](#installation)
  * [Methods](#methods)
  * [Examples](#examples)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Credits](#credits)

## Summary

* Dual pin motor control (INA, INB)<br/>
* Adjustable speed range: -255 ~ 255<br/>
* Forward, backward, and coast stop modes

## Installation

Download the library file (https://github.com/DFRobot/DFRobot_N20Motor.git) before use, paste it into the \Arduino\libraries directory, then open the sample folder and run the demo in the folder.

## Methods

```C++

  /**
   * @fn DFRobot_N20Motor
   * @brief Constructor, pins can be set here or by begin().
   * @param inA INA pin number.
   * @param inB INB pin number.
   */
  DFRobot_N20Motor(uint8_t inA = 0xFF, uint8_t inB = 0xFF);

  /**
   * @fn begin
   * @brief Initialize the motor control pins.
   * @param inA INA pin number. When set to 0xFF, keep constructor value.
   * @param inB INB pin number. When set to 0xFF, keep constructor value.
   * @return bool
   * @retval true Init success.
   * @retval false Init failed because pin is invalid.
   */
  bool begin(uint8_t inA = 0xFF, uint8_t inB = 0xFF);

  /**
   * @fn setSpeed
   * @brief Set motor speed and direction in one API.
   * @param speed Speed range: -255~255.
   * @n speed > 0: forward, speed < 0: backward, speed == 0: stop.
   */
  void setSpeed(int16_t speed);
```

## Compatibility

MCU                | Work Well    |   Work Wrong    | Untested    | Remarks
------------------ | :----------: | :-------------: | :---------: | :----:
Arduino Uno        |      √       |                 |             |
Arduino MEGA2560   |      √       |                 |             |
Arduino Leonardo   |      √       |                 |             |
FireBeetle-ESP8266 |      √       |                 |             |
FireBeetle-ESP32   |      √       |                 |             |
FireBeetle-M0      |      √       |                 |             |
Micro:bit          |              |                 |     √       |
RP2040             |      √       |                 |             |

## History

- 2026-05-09 - Version 1.0.0 released.

## Credits

Written by JiaLi(zhixinliu@dfrobot.com), 2026. (Welcome to our [website](https://www.dfrobot.com/))
