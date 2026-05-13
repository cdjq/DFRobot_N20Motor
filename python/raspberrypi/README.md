# DFRobot_N20Motor Python

===========================

* [中文版](./README_CN.md)

The N20 DC motor Python library provides dual PWM pin control for N20 micro DC motors on Raspberry Pi, supporting forward, backward, coast stop and electrical brake functions.

## Product Link ()
    SKU: DFR1276

## Table of Contents

  * [Summary](#summary)
  * [Installation](#installation)
  * [Methods](#methods)
  * [Examples](#examples)
  * [History](#history)
  * [Credits](#credits)

## Summary

* Dual pin motor control (IN_A, IN_B) using RPi.GPIO<br/>
* PWM speed control with adjustable frequency<br/>
* Forward, backward, coast stop, and brake modes<br/>
* Default GPIO: INA=GPIO12, INB=GPIO13

## Installation

Install dependency:

```bash
pip3 install RPi.GPIO
```

Copy `DFRobot_N20Motor.py` and example folder to your Raspberry Pi project.

## Methods

```python

  def __init__(self, in_a_pin=12, in_b_pin=13, pwm_frequency=5000):
    '''!
      @brief Construct the class.
      @param in_a_pin BCM pin for INA, default 12.
      @param in_b_pin BCM pin for INB, default 13.
      @param pwm_frequency PWM frequency in Hz, default 5000.
    '''

  def begin(self):
    '''!
      @brief Initialize GPIO and PWM channels.
      @return bool True if success.
    '''

  def set_speed(self, speed):
    '''!
      @brief Set speed and direction.
      @param speed Speed range: -255~255.
      @n speed > 0: forward, speed < 0: backward, speed == 0: stop.
    '''

  def forward(self, speed):
    '''!
      @brief Forward rotation.
      @param speed PWM duty input range: 0~255.
    '''

  def backward(self, speed):
    '''!
      @brief Backward rotation.
      @param speed PWM duty input range: 0~255.
    '''

  def stop(self):
    '''!
      @brief Coast stop (both outputs LOW).
    '''

  def brake(self):
    '''!
      @brief Electrical brake (both outputs HIGH).
    '''

  def get_speed(self):
    '''!
      @brief Return last set speed.
      @return int Speed -255~255.
    '''

  def get_direction(self):
    '''!
      @brief Return current direction/state.
      @return int
      @n     STOP     0, coast stop
      @n     FORWARD  1, forward
      @n     BACKWARD 2, backward
      @n     BRAKE    3, brake
    '''

  def cleanup(self):
    '''!
      @brief Release GPIO resources.
    '''
```

## History

- 2026-05-09 - Version 1.0.0 released.

## Credits

Written by JiaLi(zhixinliu@dfrobot.com), 2026. (Welcome to our [website](https://www.dfrobot.com/))
