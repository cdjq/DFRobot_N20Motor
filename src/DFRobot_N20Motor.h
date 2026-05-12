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
   * @enum eDirection_t
   * @brief Motor direction/state enumeration.
   */
  typedef enum {
    eStop = 0,      /**< Coast stop, INA=LOW, INB=LOW */
    eForward,       /**< Forward rotation */
    eBackward,      /**< Backward rotation */
    eBrake          /**< Brake, INA=HIGH, INB=HIGH */
  } eDirection_t;

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
   * @fn forward
   * @brief Forward rotation with PWM speed.
   * @param speed PWM duty, range: 0~255.
   */
  void forward(uint8_t speed);

  /**
   * @fn backward
   * @brief Backward rotation with PWM speed.
   * @param speed PWM duty, range: 0~255.
   */
  void backward(uint8_t speed);

  /**
   * @fn stop
   * @brief Coast stop (INA=LOW, INB=LOW).
   */
  void stop(void);

  /**
   * @fn brake
   * @brief Electrical brake (INA=HIGH, INB=HIGH).
   */
  void brake(void);

  /**
   * @fn getSpeed
   * @brief Get last set speed value.
   * @return int16_t Last speed, range: -255~255.
   */
  int16_t getSpeed(void) const;

  /**
   * @fn getDirection
   * @brief Get current motor direction/state.
   * @return eDirection_t
   * @n     eStop      Coast stop
   * @n     eForward   Forward rotation
   * @n     eBackward  Backward rotation
   * @n     eBrake     Electrical brake
   */
  eDirection_t getDirection(void) const;

protected:
  uint8_t _inA;
  uint8_t _inB;
  int16_t _speed;
  eDirection_t _direction;
};

#endif
