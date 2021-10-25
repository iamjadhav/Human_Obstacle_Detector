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
#include <Eigen/Dense>

/**
 * @brief Distance class to provide the pixel to SI units conversion
 *        as well as the Transformation between Camera frame and
 *        Robot frame.
 */
class Distance {
 public:
  Distance();
  std::vector<Eigen::Vector4d> camToRobotTransform(std::vector<std::vector<double>> &camXYZ);
  std::vector<double> findDepth(std::vector<double> &boxHeight);
  std::vector<std::vector<double>> getXY(std::vector<double> &depth, std::vector<cv::Rect> &r);
  void displayLocation(std::vector<Eigen::Vector4d> &locations);
  ~Distance();

 private:
  std::vector<double> pixelLocation;
  double fov = 19.2306;
  double avgHumanHeight = 175;
  double perceivedFy = 1028.57143;
  double perceivedFx = 1386.67;
  Eigen::Matrix4d poseMatrix;
};
