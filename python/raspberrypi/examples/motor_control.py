'''!
  @file motor_control.py
  @brief Example for N20 DC motor control on Raspberry Pi.
  @copyright Copyright (c) 2026 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author JiaLi(zhixin.liu@dfrobot.com)
  @version V1.0.0
  @date 2026-05-09
  @url https://github.com/DFRobot/DFRobot_N20Motor
'''

import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from DFRobot_N20Motor import DFRobot_N20Motor

n20_ina_pwm_pin = 17
n20_inb_pwm_pin = 18

motor = DFRobot_N20Motor(in_a_pin=n20_ina_pwm_pin, in_b_pin=n20_inb_pwm_pin)

def setup():
  print()
  print("========================================")
  print("  DFRobot N20 Motor")
  print("  Motor Control Example")
  print("========================================")

  if not motor.begin():
    print("[ERROR] Motor init failed, check pin configuration.")
    sys.exit(1)

  print("[OK] Motor initialized (INA PWM: {}, INB PWM: {})".format(
      n20_ina_pwm_pin, n20_inb_pwm_pin))
  print("Starting speed control loop...")
  print()


def loop():
  print("-> Speed 255")
  motor.set_speed(255)
  time.sleep(2)

  print("-> Speed 150")
  motor.set_speed(150)
  time.sleep(1.5)

  print("-> Speed -255")
  motor.set_speed(-255)
  time.sleep(2)

  print("-> Speed 0")
  motor.set_speed(0)
  time.sleep(1.5)

  print()


if __name__ == "__main__":
  try:
    setup()
    while True:
      loop()
  except KeyboardInterrupt:
    pass
  finally:
    motor.cleanup()
