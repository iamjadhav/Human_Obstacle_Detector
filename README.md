# Human_Obstacle_Detector

Human Obstacle Detector using Modern C++ Programming Language.

# Contributors

1) Abhishek Nalawade
2) Aditya Jadhav

# Overview

This project attempts to implement a Perception module for ACME Robotics using high-quality software engineering practices such as the Agile Iterative
Process, Object Oriented Programming, Pair Programming and Test Driven Development. We will attempt to achieve robust human detection using Histogram
of Oriented Gradients (HOG) feature descriptor combined with a Support Vector Machine Model. The algorithm uses HOG features extracted from the input
data to detect Humans and surround them with rectangular bounding boxes, the centers of which act as the pixel coordinates of the detected humans.
These coordinates combined with the pose matrix of the homogeneous transformation between the monocular camera and the 3D world will be used to 
track the detected humans. The pixel coordinates will be used for determining the distance of the humans with respect to the Robot’s Reference Frame.
Support Vector Machine classifier will be used to train the extracted HOG features to train the training data.

# Technology Used

We will be following the Agile Iterative Software Development Process and the Test Driven Development Process.
We will plan the work in Sprints and switch between the roles of driver and navigator throughout the process. 

- Ubuntu 18.04 LTS
- Modern C++ Programming Language
- OpenCV Library
- CMake Build System
- Doxygen 

# License 

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

# Links

AIP Process           : https://docs.google.com/spreadsheets/d/1bapR4zMCzfcwQHhxAm6KktWsMINTTPEt/edit#gid=2052063551
Sprint Planning Sheet : https://docs.google.com/document/d/1Xaz2rZ7OrmSh3bSE351XQz483VGetJkJdF37AjUF9Ro/edit
Proposal              : https://youtu.be/2ptUw7MpsMc
