/*!
 * @file DFRobot_N20Motor.cpp
 * @brief Implementation for N20 DC motor driver.
 * @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author JiaLi(zhixin.liu@dfrobot.com)
 * @version V1.0.0
 * @date 2026-05-09
 * @url https://github.com/DFRobot/DFRobot_N20Motor
 */

#include "DFRobot_N20Motor.h"

DFRobot_N20Motor::DFRobot_N20Motor(uint8_t inA, uint8_t inB)
{
  _inA = inA;
  _inB = inB;
}

bool DFRobot_N20Motor::begin(uint8_t inA, uint8_t inB)
{
  if (inA != 0xFF) {
    _inA = inA;
  }
  if (inB != 0xFF) {
    _inB = inB;
  }

  if (_inA == 0xFF || _inB == 0xFF) {
    return false;
  }

  pinMode(_inA, OUTPUT);
  pinMode(_inB, OUTPUT);
  stop();
  return true;
}

void DFRobot_N20Motor::setSpeed(int16_t speed)
{
  if (speed > 255) {
    speed = 255;
  }
  if (speed < -255) {
    speed = -255;
  }

  if (speed > 0) {
    analogWrite(_inA, (uint8_t)speed);
    analogWrite(_inB, 0);
  } else if (speed < 0) {
    analogWrite(_inA, 0);
    analogWrite(_inB, (uint8_t)(-speed));
  } else {
    stop();
  }
}

void DFRobot_N20Motor::stop(void)
{
  analogWrite(_inA, 0);
  analogWrite(_inB, 0);
  digitalWrite(_inA, LOW);
  digitalWrite(_inB, LOW);
}
