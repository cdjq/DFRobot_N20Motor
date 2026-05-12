'''!
  @file DFRobot_N20Motor.py
  @brief Implementation for N20 DC motor driver on Raspberry Pi.
  @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
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

  STOP = 0
  FORWARD = 1
  BACKWARD = 2
  BRAKE = 3

  def __init__(self, in_a_pin=12, in_b_pin=13, pwm_frequency=5000):
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
    self._speed = 0
    self._direction = self.STOP

  def begin(self):
    '''!
      @brief Initialize GPIO and PWM channels.
      @return bool True if success.
    '''
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(self._in_a_pin, GPIO.OUT)
    GPIO.setup(self._in_b_pin, GPIO.OUT)

    self._pwm_a = GPIO.PWM(self._in_a_pin, self._pwm_frequency)
    self._pwm_b = GPIO.PWM(self._in_b_pin, self._pwm_frequency)
    self._pwm_a.start(0)
    self._pwm_b.start(0)

    self.stop()
    return True

  def set_speed(self, speed):
    '''!
      @brief Set speed and direction.
      @param speed Speed range: -255~255.
    '''
    if speed > 255:
      speed = 255
    if speed < -255:
      speed = -255

    if speed > 0:
      self.forward(speed)
    elif speed < 0:
      self.backward(-speed)
    else:
      self.stop()

  def forward(self, speed):
    '''!
      @brief Forward rotation.
      @param speed PWM duty input range: 0~255.
    '''
    duty = self._to_duty(speed)
    self._pwm_a.ChangeDutyCycle(duty)
    self._pwm_b.ChangeDutyCycle(0)
    self._speed = int(speed)
    self._direction = self.FORWARD

  def backward(self, speed):
    '''!
      @brief Backward rotation.
      @param speed PWM duty input range: 0~255.
    '''
    duty = self._to_duty(speed)
    self._pwm_a.ChangeDutyCycle(0)
    self._pwm_b.ChangeDutyCycle(duty)
    self._speed = -int(speed)
    self._direction = self.BACKWARD

  def stop(self):
    '''!
      @brief Coast stop.
    '''
    self._pwm_a.ChangeDutyCycle(0)
    self._pwm_b.ChangeDutyCycle(0)
    self._speed = 0
    self._direction = self.STOP

  def brake(self):
    '''!
      @brief Brake (both outputs high duty).
    '''
    self._pwm_a.ChangeDutyCycle(100)
    self._pwm_b.ChangeDutyCycle(100)
    self._speed = 0
    self._direction = self.BRAKE

  def get_speed(self):
    '''!
      @brief Return last speed.
      @return int Speed -255~255.
    '''
    return self._speed

  def get_direction(self):
    '''!
      @brief Return current direction/state.
      @return int STOP/FORWARD/BACKWARD/BRAKE.
    '''
    return self._direction

  def cleanup(self):
    '''!
      @brief Release GPIO resources.
    '''
    if self._pwm_a is not None:
      self._pwm_a.stop()
    if self._pwm_b is not None:
      self._pwm_b.stop()
    GPIO.cleanup((self._in_a_pin, self._in_b_pin))

  @staticmethod
  def _to_duty(speed):
    speed = int(speed)
    if speed < 0:
      speed = 0
    if speed > 255:
      speed = 255
    return (speed / 255.0) * 100.0
