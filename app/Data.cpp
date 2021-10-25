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
#include <Eigen/Dense>

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
  std::string frameInput = "camera";
  cv::VideoCapture cap(mode);
    if (cap.isOpened() == false) {
      std::cout << "Camera cannot be opened! " << std::endl;
      return 3;
    } else {
        while (true) {
            std::vector<std::vector<double>> coor;
            std::vector<Eigen::Vector4d> finalLocations;
            std::vector<double> heights;
            std::vector<double> depths;
            std::vector<double> temp;
            cap >> frame;
            if (frame.empty())
              break;
            resizedFrame = preProcessing(frame);
            temp = human_detector.detectHuman(resizedFrame);
            heights = human_detector.putBox(resizedFrame,temp);
            depths = dist.findDepth(heights);
            coor = dist.getXY(depths, human_detector.box_coordinates);
            finalLocations = dist.camToRobotTransform(coor);
            dist.displayLocation(finalLocations, frameInput);
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
double Data::loadVideo(std::string filePath) {
  frame.release();
  double locx;
  std::string frameInput = "video";
  cv::VideoCapture cap(filePath);
    if (cap.isOpened() == false) {
      std::cout << "Video File cannot be opened! " << std::endl;
      return 3;
    } else {
        while (true) {
          std::vector<std::vector<double>> coor;
          std::vector<Eigen::Vector4d> finalLocations;
          std::vector<double> heights;
          std::vector<double> depths;
          std::vector<double> temp;
          cap >> frame;
          if (frame.empty())
            break;
          resizedFrame = videoPreProcessing(frame);
          temp = human_detector.detectHuman(resizedFrame);
          heights = human_detector.putBox(resizedFrame,temp);
          depths = dist.findDepth(heights);
          coor = dist.getXY(depths, human_detector.box_coordinates);
          finalLocations = dist.camToRobotTransform(coor);
          dist.displayLocation(finalLocations, frameInput);
          cv::imshow("Detected Humans", resizedFrame);
          cv::waitKey(1);
          char q = static_cast<char> (cv::waitKey(25));
          locx = finalLocations[0][0]/1000;
          if (q == 27) {
            break;
          }
        }
      cap.release();
      cv::destroyAllWindows();
    }
    return locx;
}

/**
 * @brief To resize and filter input images to operate on
 * @param frame : Frame to be preprocessed
 * @return cv::Mat
 */
cv::Mat Data::preProcessing(const cv::Mat &frame) {
  frame_copy = frame.clone();
  int row, col;
  cv::resize(frame_copy, resizedFrame, cv::Size(frame_copy.cols*2,
              frame_copy.rows*2));
  return resizedFrame;
}

/**
 * @brief To resize and filter input video frames to operate on
 * @param frame : Frame to be preprocessed
 * @return cv::Mat
 */
cv::Mat Data::videoPreProcessing(const cv::Mat &frame) {
  frame_copy = frame.clone();
  int row, col;
  cv::resize(frame_copy, resizedFrame, cv::Size((int)frame_copy.cols/2,
              (int)frame_copy.rows/2));
  return resizedFrame;
}

/**
 * @brief Destroy the Data:: Data object
 */
Data::~Data() {}
