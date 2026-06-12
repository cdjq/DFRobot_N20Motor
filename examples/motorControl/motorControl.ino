/*!
 * @file motorControl.ino
 * @brief Example for N20 DC motor control.
 * @details This example drives the motor forward and backward with different speeds,
 * @n then stops.
 * @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author JiaLi(zhixin.liu@dfrobot.com)
 * @version V1.0.0
 * @date 2026-05-09
 * @url https://github.com/DFRobot/DFRobot_N20Motor
 */

#include "DFRobot_N20Motor.h"

#if defined(ESP32)
#define N20_INA_PIN D5
#define N20_INB_PIN D6
#else
#define N20_INA_PIN 4
#define N20_INB_PIN 5
#endif

DFRobot_N20Motor motor(N20_INA_PIN, N20_INB_PIN);

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println(F("========================================"));
  Serial.println(F("  DFRobot N20 Motor"));
  Serial.println(F("  Motor Control Example"));
  Serial.println(F("========================================"));

  if (!motor.begin()) {
    Serial.println(F("[ERROR] Motor init failed, check pin configuration."));
    while (1) {
      delay(100);
    }
  }

  Serial.print(F("[OK] Motor initialized (INA: "));
  Serial.print(N20_INA_PIN);
  Serial.print(F(", INB: "));
  Serial.print(N20_INB_PIN);
  Serial.println(F(")"));
  Serial.println(F("Starting speed control loop..."));
  Serial.println();
}

void loop()
{
  Serial.println(F("-> Speed 255"));
  motor.setSpeed(255);
  delay(2000);

  Serial.println(F("-> Speed 150"));
  motor.setSpeed(150);
  delay(1500);

  Serial.println(F("-> Speed -255"));
  motor.setSpeed(-255);
  delay(2000);

  Serial.println(F("-> Stop"));
  motor.stop();
  delay(1500);

  Serial.println();
}
