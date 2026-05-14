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

import sys
import os
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import time
from DFRobot_N20Motor import DFRobot_N20Motor


def main():
  motor = DFRobot_N20Motor(in_a_pin=17, in_b_pin=18)
  motor.begin()

  try:
    while True:
      motor.set_speed(180)
      time.sleep(2)

      motor.set_speed(-180)
      time.sleep(2)

      motor.stop()
      time.sleep(1)
  except KeyboardInterrupt:
    pass
  finally:
    motor.cleanup()


if __name__ == "__main__":
  main()
