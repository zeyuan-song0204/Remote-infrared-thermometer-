
import RPi.GPIO as GPIO
import time

Buzzer = 11

CL = [0, 131, 147, 165, 175, 196, 211, 248]     
CM = [0, 262, 294, 330, 350, 393, 441, 495]    
CH = [0, 525, 589, 661, 700, 786, 882, 990]     

song_1 = [  CM[3], CM[5], CM[6], CM[3], CM[2], CM[3], CM[5], CM[6], 
            CH[1], CM[6], CM[5], CM[1], CM[3], CM[2], CM[2], CM[3], 
            CM[5], CM[2], CM[3], CM[3], CL[6], CL[6], CL[6], CM[1],
            CM[2], CM[3], CM[2], CL[7], CL[6], CM[1], CL[5] ]

beat_1 = [  1, 1, 3, 1, 1, 3, 1, 1,             
            1, 1, 1, 1, 1, 1, 3, 1, 
            1, 3, 1, 1, 1, 1, 1, 1, 
            1, 2, 1, 1, 1, 1, 1, 1, 
            1, 1, 3 ]

song_2 = [  CM[1], CM[1], CM[1], CL[5], CM[3], CM[3], CM[3], CM[1], 
            CM[1], CM[3], CM[5], CM[5], CM[4], CM[3], CM[2], CM[2], 
            CM[3], CM[4], CM[4], CM[3], CM[2], CM[3], CM[1], CM[1], 
            CM[3], CM[2], CL[5], CL[7], CM[2], CM[1]    ]

beat_2 = [  1, 1, 2, 2, 1, 1, 2, 2,             
            1, 1, 2, 2, 1, 1, 3, 1, 
            1, 2, 2, 1, 1, 2, 2, 1, 
            1, 2, 2, 1, 1, 3 ]

song_3 = [  CM[1], CM[2], CM[3], CL[4], CM[5], CM[6], CM[7], CM[7], 
            CM[6], CM[5], CM[4], CM[3], CM[2], CM[1]    ]

beat_3 = [  3, 1, 3, 1, 3, 1, 3, 1,             
            1, 1, 1, 1, 1, 1, 1, 1, 
            1, 1, 1, 1, 1, 1, 1, 1, 
            1, 1, 1, 1, 1, 1 ]

def setup():
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BOARD)        
    GPIO.setup(Buzzer, GPIO.OUT)    
    global Buzz                     
    Buzz = GPIO.PWM(Buzzer, 440)    #initial rate=400
    Buzz.start(50)                  

def loop():
    while True:
        '''print('\n    Playing song 1...')
        for i in range(1, len(song_1)):    
            Buzz.ChangeFrequency(song_1[i]) 
            time.sleep(beat_1[i] * 0.5)     
        time.sleep(1)'''                       

        print('\n\n    Playing song 2...')
        for i in range(1, len(song_2)):     
            Buzz.ChangeFrequency(song_2[i]) 
            time.sleep(beat_2[i] * 0.5)     

def destory():
    Buzz.stop()                 
    GPIO.output(Buzzer, 1)      
    GPIO.cleanup()              

if __name__ == '__main__':      
    setup()
    try:
        loop()
    except KeyboardInterrupt:   
        destory()
