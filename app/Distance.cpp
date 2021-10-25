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

#include <Eigen/Dense>
#include <iostream>
#include <string>
#include "../include/Distance.hpp"
#include <opencv2/opencv.hpp>


/**
 * @brief Construct a new Detect:: Detect object
 */
Distance::Distance() {}

/**
 * @brief Transformation between camera and robot frame
 * @param camXYZ : Camera frame X Y coordinates
 * @return std::vector<Eigen::Vector4d> :
 */
std::vector<Eigen::Vector4d> Distance::camToRobotTransform(
                                    std::vector<std::vector<double>> &camXYZ) {
  std::vector<Eigen::Vector4d> locations;
  poseMatrix << 1, 0, 0, 1,
                0, 1, 0, 2,
                0, 0, 1, 0,
                0, 0, 0, 1;
  Eigen::Vector4d robotXYZ;
  for (std::vector<double> i : camXYZ) {
    Eigen::Vector4d xyz(i[0], i[1], i[2], 1);
    robotXYZ << poseMatrix * xyz;
    locations.push_back(robotXYZ);
  }
  return locations;
}

/**
 * @brief Finds depth of the detected humans
 * @param boxHeight : contains the heights of all detected boxes
 * @return std::vector<double> :
 */
std::vector<double> Distance::findDepth(std::vector<double> &boxHeight) {
  std::vector<double> depth;
  for (double i : boxHeight) {
    double tempDepth;
    tempDepth = (perceivedFy * avgHumanHeight)/(i/4);
    depth.push_back(tempDepth);
  }
  return depth;
}

/**
 * @brief Gets the X and Y coordinates w.r.t camera frame
 * @param depth : contains the estimated depth of detected humans
 * @param r : contains the detected boxes of humans
 * @return std::vector<std::vector<double>> :
 */
std::vector<std::vector<double>> Distance::getXY(std::vector<double> &depth,
                                                  std::vector<cv::Rect> &r) {
  std::vector<std::vector<double>> worldCoordinates;
  for (unsigned int i = 0; i < depth.size(); i++) {
    double X, Y, centx, centy;
    std::vector<double> xyzCoordinates;
    // cetroid of human in pixel coordinates
    centx = r[i].x + (r[i].width/2);
    centy = r[i].y + (r[i].height/2);
    // camera frame X coordinate
    X = ((640-centx)*(depth[i]))/(perceivedFx);
    Y = ((360-centy)*(depth[i]))/(perceivedFy);
    xyzCoordinates.push_back(X);
    xyzCoordinates.push_back(Y);
    xyzCoordinates.push_back(depth[i]);
    worldCoordinates.push_back(xyzCoordinates);
  }
  return worldCoordinates;
}


/**
 * @brief To display the location of detected humans on-screen.
 * @param locations : contians human locations in robot reference frame
 * @param frameInput : contians the name of input type eg camera or video
 * @return int :
 */
int Distance::displayLocation(std::vector<Eigen::Vector4d> &locations,
                              std::string &frameInput) {
  int id = 0;
  for (Eigen::Vector4d i : locations) {
    if (frameInput == "camera") {
      std::cout << "Detected human [" << id+1 << "] is located at (meters) \n"
                <<"X: " << std::setprecision(3) << i[0]/100 <<" Y: "<<
                 std::setprecision(3) << i[1]/100 <<" Depth: " <<
                 std::setprecision(3) << i[2]/100 << "\n\n";
    } else if (frameInput == "video") {
      std::cout << "Detected human [" << id+1 << "] is located at (meters) \n"
                <<"X: " << std::setprecision(3) << i[0]/1000 <<" Y: "<<
                 std::setprecision(3) << i[1]/1000 <<" Depth: " <<
                 std::setprecision(3) << i[2]/1000 << "\n\n";
    }
    id++;
  }
  return id;
}

/**
 * @brief Destroy the Distance:: Distance object
 */
Distance::~Distance() {}
