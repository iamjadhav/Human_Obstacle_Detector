/**
 * @file Distance.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Distance Class Definition
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../include/Distance.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Detect:: Detect object
 */
Distance::Distance() {}

/**
 * @brief Transformation between camera and robot frame
 */
int Distance::camToRobotTransform() {
  std::vector<double> transform = {1, 2, 3, 4};
  int len = transform.size();
  return len;
}

/**
 * @brief To display the location of detected humans on-screen.
 */
void Distance::displayLocation() {
}

/**
 * @brief Destroy the Distance:: Distance object
 */
Distance::~Distance() {}
