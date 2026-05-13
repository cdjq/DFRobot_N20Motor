# DFRobot_N20Motor

===========================

* [English Version](./README.md)

N20 直流电机驱动库，使用双 PWM 引脚控制 N20 微型直流电机，支持正转、反转、空转停止和电子刹车功能。

![产品图片]

## 产品链接 ()
    SKU: DFR1276

## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [示例](#示例)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

* 双引脚电机控制（INA、INB）<br/>
* 速度范围：-255 ~ 255<br/>
* 支持正转、反转、空转停止、刹车四种模式

## 库安装

使用前请下载库文件（https://github.com/DFRobot/DFRobot_N20Motor.git），将其粘贴到 \Arduino\libraries 目录中，然后打开示例文件夹并运行其中的演示。

## 方法

```C++

  /**
   * @fn DFRobot_N20Motor
   * @brief 构造函数，可通过此处或 begin() 设置引脚。
   * @param inA INA 引脚号。
   * @param inB INB 引脚号。
   */
  DFRobot_N20Motor(uint8_t inA = 0xFF, uint8_t inB = 0xFF);

  /**
   * @fn begin
   * @brief 初始化电机控制引脚。
   * @param inA INA 引脚号，设为 0xFF 时保持构造函数的值。
   * @param inB INB 引脚号，设为 0xFF 时保持构造函数的值。
   * @return bool
   * @retval true 初始化成功。
   * @retval false 初始化失败，引脚无效。
   */
  bool begin(uint8_t inA = 0xFF, uint8_t inB = 0xFF);

  /**
   * @fn setSpeed
   * @brief 通过一个 API 同时设置速度和方向。
   * @param speed 速度范围：-255~255。
   * @n speed > 0: 正转，speed < 0: 反转，speed == 0: 停止。
   */
  void setSpeed(int16_t speed);

  /**
   * @fn forward
   * @brief PWM 正转。
   * @param speed PWM 占空比，范围：0~255。
   */
  void forward(uint8_t speed);

  /**
   * @fn backward
   * @brief PWM 反转。
   * @param speed PWM 占空比，范围：0~255。
   */
  void backward(uint8_t speed);

  /**
   * @fn stop
   * @brief 空转停止（INA=LOW, INB=LOW）。
   */
  void stop(void);

  /**
   * @fn brake
   * @brief 电子刹车（INA=HIGH, INB=HIGH）。
   */
  void brake(void);

  /**
   * @fn getSpeed
   * @brief 获取最近一次设置的速度值。
   * @return int16_t 最近速度，范围：-255~255。
   */
  int16_t getSpeed(void) const;

  /**
   * @fn getDirection
   * @brief 获取当前电机方向/状态。
   * @return eDirection_t
   * @n     eStop      空转停止
   * @n     eForward   正转
   * @n     eBackward  反转
   * @n     eBrake     电子刹车
   */
  eDirection_t getDirection(void) const;
```

## 兼容性

MCU                | Work Well    |   Work Wrong    | Untested    | Remarks
------------------ | :----------: | :-------------: | :---------: | :----:
Arduino Uno        |      √       |                 |             |
Arduino MEGA2560   |      √       |                 |             |
Arduino Leonardo   |      √       |                 |             |
FireBeetle-ESP8266 |      √       |                 |             |
FireBeetle-ESP32   |      √       |                 |             |
FireBeetle-M0      |      √       |                 |             |
Micro:bit          |              |                 |     √       |

## 历史

- 2026-05-09 - 发布 1.0.0 版本。

## 创作者

Written by JiaLi(zhixinliu@dfrobot.com), 2026. (Welcome to our [website](https://www.dfrobot.com/))
