/**
 * MIT License

 * Copyright (c) 2021 Abhishek Nalawade, Aditya Jadhav

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

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

#include <Eigen/Dense>
#include <gtest/gtest.h>
#include <string>
#include "../include/Distance.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Test to verify if the correct tranformation is applied.
 */
TEST(TransformTest, check_Robot_Transform) {
  Distance testDist;
  std::vector<std::vector<double>> testVector = {{0, 3, 1} };
  // 1 5 1 1
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][0], 1);
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][1], 5);
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][2], 1);
  EXPECT_EQ(testDist.camToRobotTransform(testVector)[0][3], 1);
}

/**
 * @brief TEST to verify X and Y coordinates
 */
TEST(xyCoordinatesTest, getXY) {
  Distance testDist;
  std::vector<double> depth = {444};
  cv::Rect r(100, 200, 100, 100);
  std::vector<cv::Rect> box;
  box.push_back(r);
  EXPECT_NEAR(testDist.getXY(depth, box)[0][0], 156.8938, 0.1);
  EXPECT_NEAR(testDist.getXY(depth, box)[0][1], 47.4833, 0.1);
  EXPECT_EQ(testDist.getXY(depth, box)[0][2], depth[0]);
}

/**
 * @brief TEST to verify depth of humans
 */
TEST(DepthTest, findDepth) {
  Distance testDist;
  std::vector<double> box = {500};
  EXPECT_NEAR(testDist.findDepth(box)[0], 1440, 0.1);
}

/**
 * @brief TEST verifying location placement on the screen
 */
TEST(DisplayLocation, checking_location) {
  Eigen::Vector4d loc(1.6, 0.8, 3.6, 1);
  std::vector<Eigen::Vector4d> locations;
  locations.push_back(loc);
  std::string frameInput = "camera";
  Distance testDist;
  EXPECT_EQ(testDist.displayLocation(locations, frameInput), 1);
}
