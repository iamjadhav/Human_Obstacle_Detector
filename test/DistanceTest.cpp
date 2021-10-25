/**
 * @file DistanceTest.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Distance Class Tests
 * @version 0.1
 * @date 2021-10-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <gtest/gtest.h>
#include <string>
#include "../include/Distance.hpp"
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

/**
 * @brief Test to verify if the correct tranformation is applied.
 */
TEST(TransformTest, check_Robot_Transform){
  Distance testDist;
  std::vector<Eigen::Vector4d> result;
  std::vector<std::vector<double>> testVector= {{0,3,1}};
  // 1 5 1 1
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][0], 1);
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][1], 5);
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][2], 1);
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][3], 1);
}

TEST(xyCoordinatesTest, getXY){
  Distance testDist;
  std::vector<double> depth = {444};
  cv::Rect r(100,200,100,100);
  std::vector<cv::Rect> box;
  box.push_back(r);
  std::vector<std::vector<double>> world;
  EXPECT_NEAR(testDist.getXY(depth, box)[0][0], 156.8938, 0.1);
  EXPECT_NEAR(testDist.getXY(depth, box)[0][1], 47.4833, 0.1);
  EXPECT_EQ(testDist.getXY(depth, box)[0][2], depth[0]);
}

TEST(DepthTest, findDepth){
  Distance testDist;
  std::vector<double> box = {500};
  std::vector<double> depth;
  EXPECT_NEAR(testDist.findDepth(box)[0],1440,0.1);
}

TEST(DisplayLocation, checking_location){
  Eigen::Vector4d loc(1.6, 0.8, 3.6, 1);
  std::vector<Eigen::Vector4d> locations;
  locations.push_back(loc);
  std::string frameInput = "camera";
  Distance testDist;
  EXPECT_EQ(testDist.displayLocation(locations, frameInput),1);
}
