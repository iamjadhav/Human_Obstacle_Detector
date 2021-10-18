/**
 * @file Detect.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Detect Class Definition
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../include/Detect.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Detect:: Detect object
 */
Detect::Detect() {}

/**
 * @brief Method to detect humans in input frames
 * @param input_frame 
 * @return std::vector<cv::Rect> 
 */
void Detect::detectHuman(cv::Mat &input_frame) {
    HOG.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
}

/**
 * @brief Method to draw bouding boxes around detected humans
 * @param input_frame 
 * @return int 
 */
void Detect::putBox(cv::Mat &input_frame) {
}

/**
 * @brief Destroy the Detect:: Detect object
 */
Detect::~Detect() {}
