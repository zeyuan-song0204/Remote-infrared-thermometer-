# Remote Infrared Face Thermometer Alertor :computer:
Contactless infrared thermomter System for Covid-19 epidemic prevention and control.## About The Project
## Build with
:running:Zeyuan Song(2605623s)<br>:running:Weinan Wang(2583409w)<br>:running:Yufei Liu(2572166l)
## Hardware
- [Raspberry Pi 4 B](https://www.amazon.co.uk/gp/product/B07WKKS471/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1)
- [CSI Infraed Camera Module](https://www.amazon.co.uk/gp/product/B071718FDK/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)
- [LED Traffic Light](https://www.amazon.co.uk/SHANG-JUN-assemble-Electronic-Building-r-d-u-i-n/dp/B08QM5ST11/ref=sr_1_12?dchild=1&keywords=led+traffic+light+module&qid=1613447804&sr=8-12)
- [Buzzer Module](https://www.amazon.co.uk/Keyestudio-Active-KS-018-Arduino-Raspberry/dp/B077K9BFZM/ref=sr_1_3?dchild=1&keywords=raspberry+pi+buzzer&qid=1613448001&sr=8-3)
- [Thermal Imager(GY-AMG8833)](https://www.amazon.co.uk/ICQUANZX-GY-AMG8833-Infrared-Thermal-Temperature/dp/B07Z21K8YC/ref=sr_1_3?dchild=1&keywords=AMG8833&qid=1613448066&sr=8-3)
- [GPIO extender](https://www.amazon.co.uk/WINGONEER%C2%AE-Breakout-Expansion-Ribbon-Raspberry/dp/B01N562X2P/ref=sr_1_3?crid=6J10DRP2SKJH&dchild=1&keywords=raspberry+pi+gpio+extender&qid=1613447926&sprefix=raspberry+pi+gpio%2Caps%2C152&sr=8-3)
## Getting started
### Installation
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
- **Camera installation**<br>
   Enable the Camera Interface
   ```
      sudo raspi-config
   ```
   Test camera
   ```
      raspistill -o Desktop/image.jpg -w 500 -h 500
   ```
