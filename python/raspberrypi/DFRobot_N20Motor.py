'''!
  @file DFRobot_N20Motor.py
  @brief Implementation for N20 DC motor driver on Raspberry Pi.
  @copyright Copyright (c) 2026 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author JiaLi(zhixin.liu@dfrobot.com)
  @version V1.0.0
  @date 2026-05-09
  @url https://github.com/DFRobot/DFRobot_N20Motor
'''

import RPi.GPIO as GPIO


class DFRobot_N20Motor:
  '''!
    @brief N20 DC motor control class for Raspberry Pi.
  '''

  def __init__(self, in_a_pin=17, in_b_pin=18, pwm_frequency=5000):
    '''!
      @brief Construct the class.
      @param in_a_pin BCM pin for INA.
      @param in_b_pin BCM pin for INB.
      @param pwm_frequency PWM frequency in Hz.
    '''
    self._in_a_pin = in_a_pin
    self._in_b_pin = in_b_pin
    self._pwm_frequency = pwm_frequency
    self._pwm_a = None
    self._pwm_b = None
    self._initialized = False

  def begin(self):
    '''!
      @brief Initialize GPIO and PWM channels.
      @return bool True: success, False: failed.
    '''
    if not self._is_valid_pin(self._in_a_pin) or not self._is_valid_pin(self._in_b_pin):
      return False

    try:
      GPIO.setmode(GPIO.BCM)
      GPIO.setup(self._in_a_pin, GPIO.OUT)
      GPIO.setup(self._in_b_pin, GPIO.OUT)

      self._pwm_a = GPIO.PWM(self._in_a_pin, self._pwm_frequency)
      self._pwm_b = GPIO.PWM(self._in_b_pin, self._pwm_frequency)
      self._pwm_a.start(0)
      self._pwm_b.start(0)

      self._initialized = True
      return True
    except (RuntimeError, ValueError):
      self._initialized = False
      return False

  def set_speed(self, speed):
    '''!
      @brief Set speed and direction.
      @param speed Speed range: -255~255.
      @return bool True: success, False: failed.
    '''
    if not self._initialized or self._pwm_a is None or self._pwm_b is None:
      return False

    if speed > 255:
      speed = 255
    if speed < -255:
      speed = -255

    try:
      if speed > 0:
        duty = self._to_duty(speed)
        self._pwm_a.ChangeDutyCycle(duty)
        self._pwm_b.ChangeDutyCycle(0)
      elif speed < 0:
        duty = self._to_duty(-speed)
        self._pwm_a.ChangeDutyCycle(0)
        self._pwm_b.ChangeDutyCycle(duty)
      else:
        self._pwm_a.ChangeDutyCycle(0)
        self._pwm_b.ChangeDutyCycle(0)
      return True
    except RuntimeError:
      return False

  def cleanup(self):
    '''!
      @brief Release GPIO resources.
      @return bool True: success, False: failed.
    '''
    try:
      if self._pwm_a is not None:
        self._pwm_a.stop()
      if self._pwm_b is not None:
        self._pwm_b.stop()
      GPIO.cleanup((self._in_a_pin, self._in_b_pin))
      self._initialized = False
      return True
    except RuntimeError:
      return False

  @staticmethod
  def _is_valid_pin(pin):
    return isinstance(pin, int) and 0 <= pin <= 27

  @staticmethod
  def _to_duty(speed):
    speed = int(speed)
    if speed < 0:
      speed = 0
    if speed > 255:
      speed = 255
    return (speed / 255.0) * 100.0
