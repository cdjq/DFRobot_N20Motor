'''!
  @file motor_control.py
  @brief Example for N20 DC motor control on Raspberry Pi.
  @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
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

INA_PIN = 17
INB_PIN = 18


def main():
  motor = DFRobot_N20Motor(in_a_pin=INA_PIN, in_b_pin=INB_PIN)

  print()
  print("========================================")
  print("  DFRobot N20 Motor")
  print("  Motor Control Example")
  print("========================================")

  if not motor.begin():
    print("[ERROR] Motor init failed, check pin configuration.")
    return

  print("[OK] Motor initialized (INA: {}, INB: {})".format(INA_PIN, INB_PIN))
  print("Starting speed control loop...")
  print()

  try:
    while True:
      print("-> Speed 255")
      motor.set_speed(255)
      time.sleep(2)

      print("-> Speed 150")
      motor.set_speed(150)
      time.sleep(1.5)

      print("-> Speed -255")
      motor.set_speed(-255)
      time.sleep(2)

      print("-> Stop")
      motor.stop()
      time.sleep(1.5)

      print()
  except KeyboardInterrupt:
    pass
  finally:
    motor.cleanup()


if __name__ == "__main__":
  main()
