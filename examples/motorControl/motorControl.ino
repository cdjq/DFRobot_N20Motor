/*!
 * @file motorControl.ino
 * @brief Example for N20 DC motor control.
 * @details This example drives the motor forward and backward with different speeds,
 * @n then brakes and stops.
 * @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author JiaLi(zhixin.liu@dfrobot.com)
 * @version V1.0.0
 * @date 2026-05-09
 * @url https://github.com/DFRobot/DFRobot_N20Motor
 */

#include "DFRobot_N20Motor.h"

#if defined(ARDUINO_ARCH_ESP32)
#define N20_INA_PIN D5
#define N20_INB_PIN D6
#else
#define N20_INA_PIN 10
#define N20_INB_PIN 11
#endif

DFRobot_N20Motor motor(N20_INA_PIN, N20_INB_PIN);

void setup()
{
  Serial.begin(115200);
  if (!motor.begin()) {
    Serial.println("N20 motor init failed, check pin configuration.");
    while (1) {
      delay(100);
    }
  }
}

void loop()
{
  motor.setSpeed(180);
  delay(2000);

  motor.setSpeed(80);
  delay(1500);

  motor.setSpeed(-180);
  delay(2000);

  motor.brake();
  delay(1000);

  motor.stop();
  delay(1500);
}
