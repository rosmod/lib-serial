Serial Port library for sendind and receiving data
=================================

Install Build Tools
-------------------------

```bash
sudo apt-get install python-catkin-tools
```

Build Library:
-------------

```bash
cd
mkdir catkin_ws #if a workspace does not already exist
cd catkin_ws
git clone https://github.com/rosmod/lib-serial.git src/lib-serial
catkin build serial
```

Update Library:
-----------------

```bash
cd ~/catkin_ws
catkin clean serial
cd src/lib-serial
git pull
cd ..
catkin build serial
```


Rosmod Source Library Setup:
-------------------------------

1. In this github repo navigate to [releases](https://github.com/rosmod/lib-serial/releases), right click on `serial.zip` (not the source code zip!) and select `Copy link address'
2. In a rosmod project, drag in a new source library to the software model
3. Paste the link in the url attribute
4. Name the source library `serial`
5. Drag the library into the `set editor` of any component that uses it
6. In the forwards section of the component add `#include "serial/SerialPort.h"`
