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
  _speed = 0;
  _direction = eStop;
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
    forward((uint8_t)speed);
  } else if (speed < 0) {
    backward((uint8_t)(-speed));
  } else {
    stop();
  }
}

void DFRobot_N20Motor::forward(uint8_t speed)
{
  analogWrite(_inA, speed);
  analogWrite(_inB, 0);
  _speed = speed;
  _direction = eForward;
}

void DFRobot_N20Motor::backward(uint8_t speed)
{
  analogWrite(_inA, 0);
  analogWrite(_inB, speed);
  _speed = -(int16_t)speed;
  _direction = eBackward;
}

void DFRobot_N20Motor::stop(void)
{
  analogWrite(_inA, 0);
  analogWrite(_inB, 0);
  digitalWrite(_inA, LOW);
  digitalWrite(_inB, LOW);
  _speed = 0;
  _direction = eStop;
}

void DFRobot_N20Motor::brake(void)
{
  digitalWrite(_inA, HIGH);
  digitalWrite(_inB, HIGH);
  _speed = 0;
  _direction = eBrake;
}

int16_t DFRobot_N20Motor::getSpeed(void) const
{
  return _speed;
}

DFRobot_N20Motor::eDirection_t DFRobot_N20Motor::getDirection(void) const
{
  return _direction;
}
