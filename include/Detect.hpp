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
  std::vector<cv::Rect> box_coordinates;
  cv::HOGDescriptor HOG;
  std::vector<double> detectHuman(cv::Mat &input_frame);
  std::vector<double> putBox(cv::Mat &input_frame, std::vector<double> &weights);
  ~Detect();

 private:

};
