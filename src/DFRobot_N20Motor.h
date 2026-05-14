/*!
 * @file DFRobot_N20Motor.h
 * @brief Declaration for N20 DC motor driver library.
 * @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author JiaLi(zhixin.liu@dfrobot.com)
 * @version V1.0.0
 * @date 2026-05-09
 * @url https://github.com/DFRobot/DFRobot_N20Motor
 */
#ifndef DFROBOT_N20MOTOR_H
#define DFROBOT_N20MOTOR_H

#include "Arduino.h"

class DFRobot_N20Motor {
public:
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
   * @return true Init success.
   * @return false Init failed because pin is invalid.
   */
  bool begin(uint8_t inA = 0xFF, uint8_t inB = 0xFF);

  /**
   * @fn setSpeed
   * @brief Set motor speed and direction in one API.
   * @param speed Speed range: -255~255.
   * @n speed > 0: forward, speed < 0: backward, speed == 0: stop.
   */
  void setSpeed(int16_t speed);

  /**
   * @fn stop
   * @brief Coast stop (INA=LOW, INB=LOW).
   */
  void stop(void);

protected:
  uint8_t _inA;
  uint8_t _inB;
};

#endif
