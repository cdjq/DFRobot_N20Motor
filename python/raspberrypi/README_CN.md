# DFRobot_N20Motor Python

===========================

* [English Version](./README.md)

N20 直流电机 Python 驱动库，用于树莓派平台双 PWM 引脚控制 N20 微型直流电机，支持正转、反转、空转停止和电子刹车功能。

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
* 支持正转、反转、空转停止、刹车四种模式<br/>
* 默认 GPIO：INA=GPIO12，INB=GPIO13

## 安装

安装依赖：

```bash
pip3 install RPi.GPIO
```

将 `DFRobot_N20Motor.py` 和示例目录拷贝到树莓派项目中即可使用。

## 方法

```python

  def __init__(self, in_a_pin=12, in_b_pin=13, pwm_frequency=5000):
    '''!
      @brief 构造函数。
      @param in_a_pin INA 的 BCM 引脚号，默认 12。
      @param in_b_pin INB 的 BCM 引脚号，默认 13。
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

  def forward(self, speed):
    '''!
      @brief 正转。
      @param speed PWM 占空比输入范围：0~255。
    '''

  def backward(self, speed):
    '''!
      @brief 反转。
      @param speed PWM 占空比输入范围：0~255。
    '''

  def stop(self):
    '''!
      @brief 空转停止（两路输出低电平）。
    '''

  def brake(self):
    '''!
      @brief 电子刹车（两路输出高电平）。
    '''

  def get_speed(self):
    '''!
      @brief 返回最近一次设置的速度。
      @return int 速度 -255~255。
    '''

  def get_direction(self):
    '''!
      @brief 返回当前方向/状态。
      @return int
      @n     STOP     0，空转停止
      @n     FORWARD  1，正转
      @n     BACKWARD 2，反转
      @n     BRAKE    3，刹车
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
