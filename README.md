## Human_Obstacle_Detector
[![Build Status](https://app.travis-ci.com/iamjadhav/Human_Obstacle_Detector.svg?branch=main)](https://app.travis-ci.com/iamjadhav/Human_Obstacle_Detector)
[![Coverage Status](https://coveralls.io/repos/github/iamjadhav/Human_Obstacle_Detector/badge.svg?branch=main)](https://coveralls.io/github/iamjadhav/Human_Obstacle_Detector?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
---

## Contributors

1) [Abhishek Nalawade](https://github.com/abhishek-nalawade)
Graduate Student of M.Eng Robotics at University of Maryland. 
2) [Aditya Jadhav](https://github.com/iamjadhav)
Graduate Student of M.Eng Robotics at University of Maryland.

## Overview

Obstacle detection has been widely studied in the field of Computer Vision. It is a crucial part of Self Driving Cars as well as Industrial Autonomous
Systems. In the case of Self Driving Cars, a sub-task of Obstacle Detection can be Detection of Humans who become obvious and high risk obstacles for 
the vehicles. The real-time Human Obstacle Detection becomes increasingly difficult in noisy and chaotic environments and hence the algorithms deployed
need to be highly efficient and robust to flimsy environmental variables. For example, color based approaches lack efficiency in unstable lighting 
environments. Deep Learning based approaches offer high efficiency but are extremely expensive to implement.

This project attempts to implement a Perception module for ACME Robotics using high-quality software engineering practices such as the Agile Iterative
Process, Object Oriented Programming, Pair Programming and Test Driven Development. We attempt to achieve robust human detection using Histogram
of Oriented Gradients (HOG) feature descriptor combined with a Support Vector Machine Model. The algorithm uses HOG features extracted from the input
data to detect Humans and surround them with rectangular bounding boxes, the centers of which act as the pixel coordinates of the detected humans.
These coordinates combined with the pose matrix of the homogeneous transformation between the monocular camera and the 3D world will be used to 
track the detected humans. The pixel coordinates will be used for determining the distance of the humans with respect to the Robot’s Reference Frame.
Support Vector Machine classifier will be used to train the extracted HOG features to train the training data.

The results of the Phase-1 are avilable in the Demo section.
The technologies(libraries, tools, systems) used in order to build this project are listed in the next section.

## Technology Used

We will be following the Agile Iterative Software Development Process and the Test Driven Development Process.
We will plan the work in Sprints and switch between the roles of driver and navigator throughout the process. 

* Ubuntu 18.04 LTS
* Modern C++ Programming Language
* OpenCV Library
* Eigen Library
* CMake Build System
* Doxygen

## Development

- For this project we have followed Agile Iterative Development Process(AIP) and Test Driven Development Process(TDD).
- The roles of Driver and Navigator were followed according to sprints of the project and switched between sprints.
- Product Backlog and Work Log can be found [here](https://docs.google.com/spreadsheets/d/1bapR4zMCzfcwQHhxAm6KktWsMINTTPEt/edit#gid=2052063551).
- Sprint Planning and Overview document can be found [here](https://docs.google.com/document/d/1Xaz2rZ7OrmSh3bSE351XQz483VGetJkJdF37AjUF9Ro/edit).

## License 

```
MIT License

Copyright (c) 2021 Abhishek Nalawade, Aditya Jadhav

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
```

## Demos and Overviews

Phase-1 Demo:

- [Phase-1](https://youtu.be/lwNjuT5e-FM)

Phase-2 Output Demo:

- [Phase-2](https://www.youtube.com/watch?v=CXsixNbqTj8)

![ezgif com-gif-maker](https://user-images.githubusercontent.com/35925489/138687478-1459cc24-4aad-42cc-9227-612790c5da71.gif)

Phase-2 Final Overview:

- [Phase-2 Overview](https://youtu.be/G9Qp9nsc6AY)

## Set of Assumptions 

- Humans are assumed to be in upright position.
- The average human height is assumed to be 175 cms (1.75 meters).
- Assumed Pin Hole camera model and Perspective Transform.

## Known Issues/Bugs 

- Human Detection is not highly efficient; Unnecessary bounding boxes are drawn for detections other than humans.
- Humans in an abnormal pose are not being detected.
- Lighting Conditions need to be favourable for good detection.
- Humans in upright positions are detected.

## Dependencies

- Install OpenCV 3.4.4 and other dependencies using this link. Refer [OpenCV](https://learnopencv.com/install-opencv-3-4-4-on-ubuntu-18-04/)

## How to build

```
git clone --recursive https://github.com/iamjadhav/Human_Obstacle_Detector
cd Human_Obstacle_Detector
mkdir build
cd build
cmake ..
make
```

To Run tests 
```
./test/cpp-test
```
To Run the program/demo
```
./app/shell-app
```

## Links

AIP Process --> [Link](https://docs.google.com/spreadsheets/d/1bapR4zMCzfcwQHhxAm6KktWsMINTTPEt/edit#gid=2052063551)

Sprint Planning Sheet--> [Link](https://docs.google.com/document/d/1Xaz2rZ7OrmSh3bSE351XQz483VGetJkJdF37AjUF9Ro/edit)

Phase-1 Overview --> [Link](https://youtu.be/lwNjuT5e-FM)

Proposal --> [Link](https://youtu.be/2ptUw7MpsMc)

Final Output and Overview --> [Link](https://youtu.be/G9Qp9nsc6AY)
