import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11,GPIO.OUT)
'''while True:
    GPIO.output(11,GPIO.HIGH)
    time.sleep(3)
    GPIO.output(11,GPIO.LOW)
    time.sleep(0.1)
    #GPIO.cleanup()'''
def beep(seconds):
    GPIO.output(11,GPIO.LOW)
    time.sleep(seconds)
    GPIO.output(11,GPIO.HIGH)

def beepAction(secs,sleepsecs,times):
    for i in range(times):
        beep(secs)
        time.sleep(sleepsecs)

try:
    beepAction(0.2,0.2,15)
except KeyboardInterrupt:
    GPIO.cleanup()
