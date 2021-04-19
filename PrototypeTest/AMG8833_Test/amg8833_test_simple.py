import busio as io
import board
import adafruit_amg88xx
import time

from time import sleep

i2c=io.I2C(board.SCL,board.SDA, frequency=100000)
amg=adafruit_amg88xx.AMG88XX(i2c)
print(i2c)
while True:
    a=amg.pixels[4][4]
    print(a)
    time.sleep(1)
