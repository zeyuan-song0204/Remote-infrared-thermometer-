# Buzzer &Led lights Test

## Install wiringPi
```
sudo apt-get install git-core

sudo apt-get update

git clone git://git.drogon.net/wiringPi

cd wiringPi

./build
```
## check
```
gpio -v
```
![image](https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/gpio%20-v.PNG)<br>
## LED lights
- Pi GND to sensor GND
- Pi GPIO26 to sensor R
- Pi GPIO19 to sensor Y
- Pi GPIO13 to sensor GSDA

<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/led%26buzzer.jpg" width="250" height="150"/><br>
## Buzzer
- Pi GND to sensor GND
- Pi I/O to sensor GPIO17
- Pi 3V3 to sensor VCC
<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/GPIO%20Extension%20Board.jpg" width="150" height="200"/>
## Result
<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/TTFR5912.GIF" width="300" height="300" />
