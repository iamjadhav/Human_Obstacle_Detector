/**
 * @file Train.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Train Class Definition
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../include/Train.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Detect:: Detect object
 */
Train::Train() {}

/**
 * @brief Training data
 */
int Train::trainSVMModel() {
  return 0;
}

/**
 * @brief Preparing data for training
 */
cv::Mat Train::dataPreProcessing() {
}

/**
 * @brief Destroy the Train:: Train object
 */
Train::~Train() {}
