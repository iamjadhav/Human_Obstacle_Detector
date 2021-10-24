/**
 * @file Distance.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Distance Class Declaration
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
 * @brief Distance class to provide the pixel to SI units conversion
 *        as well as the Transformation between Camera frame and
 *        Robot frame.
 */
class Distance {
 public:
  Distance();
  int camToRobotTransform();
  double findDepth(std::vector<double> &boxHeight);
  void displayLocation();
  ~Distance();

 private:
  std::vector<double> pixelLocation;
  double fov = 19.2306;
  double avgHumanHeight = 175;
  double perceivedFocalLength = 1028.57143;
  cv::Mat rotationMat;
};
