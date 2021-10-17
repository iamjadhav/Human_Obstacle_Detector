/**
 * @file data.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "../include/Data.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Data:: Data object
 */
Data::Data() {}

/**
 * @brief to take the camera frames as input
 * @param camMode: Camera mode to view the camera or not
 */
int Data::getCamera() {
    cv::VideoCapture cap(0);
    if (cap.isOpened() == false) {
      std::cout << "Cannot open the video camera" << std::endl;
      std::cin.get();
      return -1;
    }
}

/**
 * @brief to take frames from a video file as input frames
 * @param filePath 
 */
cv::Mat Data::loadVideo(std::string filePath) {
    cv::Mat read_image = cv::imread(filePath);
    return read_image;
}

/**
 * @brief to resize and filter input images to operate on
 */
int Data::preProcessing(const cv::Mat &frame) {
  frame_copy = frame.clone();
  int row, col;
  cv::Mat resizedFrame;
  cv::resize(frame_copy, resizedFrame, cv::Size(100, 100));
  row = resizedFrame.rows;
  col = resizedFrame.cols;
  return row;
}

/**
 * @brief Destroy the Data:: Data object
 */
Data::~Data() {}
