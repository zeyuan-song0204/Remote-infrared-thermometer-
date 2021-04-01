
## Raspberry Pi wired with I2C

<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/AMG8833.jpg" width="300" height="393"/>
- Pi 3V3 to sensor VIN
- Pi GND to sensor GND
- Pi SCL to sensor SCL
- Pi SDA to sensor SDA

## Python Installation of AMG88xx Library
```
sudo pip3 install adafruit-circuitpython-amg88xx
```
## Open i2c interface 
```
sudo raspi-config
```
Then check
```
sudo i2cdetect -y 1
```
