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
