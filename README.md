# Human_Obstacle_Detector

Human Obstacle Detector using C++

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

# Links

AIP Process: https://docs.google.com/spreadsheets/d/1bapR4zMCzfcwQHhxAm6KktWsMINTTPEt/edit#gid=2052063551
Proposal   : https://youtu.be/2ptUw7MpsMc
