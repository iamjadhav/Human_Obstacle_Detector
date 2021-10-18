/**
 * @file Detect.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Detect Class Declaration
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Detect class uses a pre-trained SVM model from openCV to detect
 *        humans in the input frames and return bounding box co-ordinates.
 */
class Detect {
 public:
  Detect();
  cv::HOGDescriptor HOG;
  std::vector<cv::Rect> detectHuman(const cv::Mat &input_frame);
  int putBox(const cv::Mat &input_frame);
  ~Detect();

 private:
};
