# DFRobot_N20Motor Python

===========================

* [中文版](./README_CN.md)

The N20 DC motor Python library provides dual PWM pin control for N20 micro DC motors on Raspberry Pi, supporting speed control, direction control and coast stop functions.

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
* Forward, backward, and coast stop modes<br/>
* Default GPIO: INA=GPIO17, INB=GPIO18

## Installation

Install dependency:

```bash
pip3 install RPi.GPIO
```

Copy `DFRobot_N20Motor.py` and example folder to your Raspberry Pi project.

## Methods

```python

  def __init__(self, in_a_pin=17, in_b_pin=18, pwm_frequency=5000):
    '''!
      @brief Construct the class.
      @param in_a_pin BCM pin for INA, default 17.
      @param in_b_pin BCM pin for INB, default 18.
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

  def stop(self):
    '''!
      @brief Coast stop (both outputs LOW).
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
