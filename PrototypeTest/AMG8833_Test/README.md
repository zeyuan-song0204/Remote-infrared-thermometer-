
## Raspberry Pi wired with I2C
<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/AMG8833_image.jpg" width="200" height="200"/><br>
- Pi 3V3 to sensor VIN
- Pi GND to sensor GND
- Pi SCL to sensor SCL
- Pi SDA to sensor SDA

## Python Installation of AMG88xx Library
```
sudo pip3 install adafruit-circuitpython-amg88xx
```
## Open i2c interface from Pi
```
sudo raspi-config
```
Interface Options--->I2C--->Enable <br>
<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/i2C_interface.PNG" width="393" height="300"/> <br>
Then check<br>
```
sudo i2cdetect -y 1
```
<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/i2C_detect.PNG" /><br>
Open i2C complete!<br>

### Run the code and result bellow
<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/Thermal%20imaging.GIF" width="400" height="400"/><br>
