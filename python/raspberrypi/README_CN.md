# DFRobot_N20Motor Python

===========================

* [English Version](./README.md)

N20 直流电机 Python 驱动库，用于树莓派平台双 PWM 引脚控制 N20 微型直流电机，支持速度控制、方向控制和空转停止功能。

## 产品链接 ()
    SKU: DFR1276

## 目录

  * [概述](#概述)
  * [安装](#安装)
  * [方法](#方法)
  * [示例](#示例)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

* 使用 RPi.GPIO 进行双引脚电机控制（IN_A、IN_B）<br/>
* PWM 调速，频率可调<br/>
* 支持正转、反转、空转停止模式<br/>
* 默认 GPIO：INA=GPIO17，INB=GPIO18

## 安装

安装依赖：

```bash
pip3 install RPi.GPIO
```

将 `DFRobot_N20Motor.py` 和示例目录拷贝到树莓派项目中即可使用。

## 方法

```python

  def __init__(self, in_a_pin=17, in_b_pin=18, pwm_frequency=5000):
    '''!
      @brief 构造函数。
      @param in_a_pin INA 的 BCM 引脚号，默认 17。
      @param in_b_pin INB 的 BCM 引脚号，默认 18。
      @param pwm_frequency PWM 频率（Hz），默认 5000。
    '''

  def begin(self):
    '''!
      @brief 初始化 GPIO 和 PWM 通道。
      @return bool 成功返回 True。
    '''

  def set_speed(self, speed):
    '''!
      @brief 设置速度和方向。
      @param speed 速度范围：-255~255。
      @n speed > 0: 正转，speed < 0: 反转，speed == 0: 停止。
    '''

  def stop(self):
    '''!
      @brief 空转停止（两路输出低电平）。
    '''

  def cleanup(self):
    '''!
      @brief 释放 GPIO 资源。
    '''
```

## 历史

- 2026-05-09 - 发布 1.0.0 版本。

## 创作者

Written by JiaLi(zhixinliu@dfrobot.com), 2026. (Welcome to our [website](https://www.dfrobot.com/))
