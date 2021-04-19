<br />
<div align="center">
    

  <b align="center" font-size="50px">Remote Infrared Thermometer Alertor</b>  
  
  <p align="center">
    Event driven COVID-19 safety
    <br />
    <a href="https://boxofhope.co.uk/docs/index.html"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://twitter.com/Leon83677052"><img height=40 src="image_forder/twitter.png"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    <a href="https://twitter.com/Leon83677052"><img height=40 src="image_forder/Facebook.png"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    <a href="https://www.instagram.com/2605623s/"><img height=40 src="image_forder/Instagram.svg.png"></img></a>&nbsp;&nbsp;&nbsp;&nbsp;
    </p>
</div>


<div >
  
## About The Project
<img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/final device.jpg" width="350" height="350"/><br>
Contactless infrared thermomter System for Covid-19 epidemic prevention and control.It can be applied in airport or train entrance as a security check during covid-19 epidemic.If it detect a person whose body temperature is above 37.5℃ which cause the red light on and buzzer ringing,then the person cann't allowd to get in the public transportation. This design aim to decline the number of virus carriers appear in public palace and reduce the spread of virus.<br> 
## Build with
:running:Zeyuan Song(2605623s)<br>:running:Weinan Wang(2583409w)<br>:running:Yufei Liu(2572166l)
## Hardware
- [Raspberry Pi 4 B](https://www.amazon.co.uk/gp/product/B07WKKS471/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1)
- [CSI Infraed Camera Module](https://www.amazon.co.uk/gp/product/B071718FDK/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)
- [LED Traffic Light](https://www.amazon.co.uk/SHANG-JUN-assemble-Electronic-Building-r-d-u-i-n/dp/B08QM5ST11/ref=sr_1_12?dchild=1&keywords=led+traffic+light+module&qid=1613447804&sr=8-12)
- [Buzzer Module](https://www.amazon.co.uk/Keyestudio-Active-KS-018-Arduino-Raspberry/dp/B077K9BFZM/ref=sr_1_3?dchild=1&keywords=raspberry+pi+buzzer&qid=1613448001&sr=8-3)
- [Thermal Imager(GY-AMG8833)](https://www.amazon.co.uk/ICQUANZX-GY-AMG8833-Infrared-Thermal-Temperature/dp/B07Z21K8YC/ref=sr_1_3?dchild=1&keywords=AMG8833&qid=1613448066&sr=8-3)
- [GPIO extender](https://www.amazon.co.uk/WINGONEER%C2%AE-Breakout-Expansion-Ribbon-Raspberry/dp/B01N562X2P/ref=sr_1_3?crid=6J10DRP2SKJH&dchild=1&keywords=raspberry+pi+gpio+extender&qid=1613447926&sprefix=raspberry+pi+gpio%2Caps%2C152&sr=8-3)
## Prerequisites
OpenCV is definitely needed to installed on Raspberry Pi.The version used for this project is 4.1.0.WiringPi is a basic library to applied on GPIO control functions.Adafruit_Blinka library provides the CircuitPython support in Python.This may alsp need to enabling I2C on Pi platform.And AMG88xx library supports AMG8833 sensor.<br>
### Camera installation and test
   Enable the Camera Interface
   ```
      sudo raspi-config
   ```
   Test camera
   ```
      raspistill -o Desktop/image.jpg -w 500 -h 500
   ```
### Installation OpenCV
- **cmake**<br>
```
   sudo apt-get install cmake
```
- **openCV-4.1.0**<br>
   1.update raspbian and Increase the swap-size
   ```
      sudo apt-get update && sudo apt-get upgrade && sudo rpi-update
      sudo nano /etc/dphys-swapfile
      #CONF_SWAPSIZE=100
      CONF_SWAPSIZE=2048
   ```
   2.Install tools and libraries for openCV
   ```
      sudo apt-get install build-essential cmake pkg-config
      sudo apt-get install libjpeg-dev libtiff5-dev libjasper-dev libpng12-dev
      sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
      sudo apt-get install libxvidcore-dev libx264-dev
      sudo apt-get install libgtk2.0-dev libgtk-3-dev
      sudo apt-get install libatlas-base-dev gfortran
   ```
   3.Get source code
   ```
      wget -O opencv.zip https://github.com/opencv/opencv/archive/4.1.0.zip
      wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.1.0.zip
      unzip opencv.zip
      unzip opencv_contrib.zip
   ```
   4.Compile openCV
   ```
      cd ~/opencv-4.1.0/
      mkdir build
      cd build
      cmake -D CMAKE_BUILD_TYPE=RELEASE \
       -D CMAKE_INSTALL_PREFIX=/usr/local \
       -D INSTALL_PYTHON_EXAMPLES=ON \
       -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib-4.1.0/modules \
       -D BUILD_EXAMPLES=ON ..
   ```
   5.Build and Install openCV
   ```
      make -j4
      sudo make install && sudo ldconfig
   ```
   6.Run face detection and result shows below<br>
   <img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/face_detection_result.jpg" width="400" height="400"><br>

   
### AMG8833 installation and test
   <img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/AMG8833.jpg" width="200" height="293"/><br>
   - Pi 3V3 to sensor VIN
   - Pi GND to sensor GND
   - Pi SCL to sensor SCL
   - Pi SDA to sensor SDA

   1.Python Installation of AMG88xx Library<br>
   ```
   sudo pip3 install adafruit-circuitpython-amg88xx
   ```
   2.Open i2c interface from Pi
   ```
   sudo raspi-config
   ```
   3.Interface Options--->I2C--->Enable <br>
   <img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/i2C_interface.PNG" width="350" height="250"/> <br>
   Then check<br>
   ```
   sudo i2cdetect -y 1
   ```
   <img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/i2C_detect.PNG" /><br>
   Open i2C complete!<br>

   4.Run the Amg8833 test code and result bellow<br>
   <img src="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/Thermal%20Imager%20result.PNG" width="250" height="250"/><br>
### Install WiringPi Lib
   1.Install wiringPi
   ```
   sudo apt-get install git-core

   sudo apt-get update

   git clone git://git.drogon.net/wiringPi

   cd wiringPi

   ./build
   ```
   2.check
   ```
   gpio -v
   ```
   ![image](https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/image_forder/gpio%20-v.PNG)<br>

   


## License
Project is distributed under <a href="https://github.com/zeyuan-song0204/Remote-infrared-thermometer-/blob/main/LICENSE">MIT License</a>
## Contact

Zeyuan Song - 2605623s@student.gla.ac.uk

Project Link: [https://github.com/zeyuan-song0204/Remote-infrared-thermometer-](https://github.com/zeyuan-song0204/Remote-infrared-thermometer-)

## Marketing
This project is marketed on Tiwtter and Instagram <br>
&nbsp;&nbsp;<a href="https://twitter.com/Leon83677052"><img src="https://i.imgur.com/0Rz10Ws.png" width="80" height="80" style="margin: 0 auto;"/></a>
&nbsp;&nbsp;&nbsp;&nbsp;<a href="https://www.instagram.com/2605623s/"><img src="https://i.imgur.com/JdLvg67.png" width="80" height="80"/></a>





