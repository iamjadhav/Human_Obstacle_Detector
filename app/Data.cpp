/**
 * @file Data.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Data Class Definition
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "../include/Data.hpp"
#include "../include/Detect.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Data:: Data object
 */
Data::Data() {}

/**
 * @brief To take the camera frames as input
 * @param mode : Camera mode to view the camera or not
 * @return int 
 */
int Data::getCamera(int mode) {
  frame.release();
  cv::VideoCapture cap(mode);
    if (cap.isOpened() == false) {
      std::cout << "Camera cannot be opened! " << std::endl;
    } else {
        while (true) {
            cap >> frame;
            resizedFrame = preProcessing(frame);
            human_detector.detectHuman(resizedFrame);
            human_detector.putBox(resizedFrame);
            cv::imshow("Detected Humans", resizedFrame);
            cv::waitKey(1);
            char q = static_cast<char> (cv::waitKey(25));
            if (q == 27) {
              break;
            }
        }
      cap.release();
      cv::destroyAllWindows();
    }
}

/**
 * @brief To take frames from a video file as input frames
 * @param filePath Path to the video file
 * @return int 
 */
int Data::loadVideo(std::string filePath) {
  frame.release();
  cv::VideoCapture cap(filePath);
    if (cap.isOpened() == false) {
      std::cout << "Video File cannot be opened! " << std::endl;
    } else {
        while (true) {
          cap >> frame;
          resizedFrame = preProcessing(frame);
          human_detector.detectHuman(resizedFrame);
          human_detector.putBox(resizedFrame);
          cv::imshow("Detected Humans", resizedFrame);
          cv::waitKey(1);
          char q = static_cast<char> (cv::waitKey(25));
          if (q == 27) {
            break;
          }
        }
      cap.release();
      cv::destroyAllWindows();
    }
}

/**
 * @brief To resize and filter input images to operate on
 * @param frame : Frame to be preprocessed
 * @return cv::Mat 
 */
cv::Mat Data::preProcessing(const cv::Mat &frame) {
  frame_copy = frame.clone();
  int row, col;
  cv::resize(frame_copy, resizedFrame, cv::Size(frame_copy.cols*2, frame_copy.rows*2));
  return resizedFrame;
}

/**
 * @brief Destroy the Data:: Data object
 */
Data::~Data() {}
