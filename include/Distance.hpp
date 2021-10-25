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

#include <Eigen/Dense>
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * @brief Distance class to provide the pixel to SI units conversion
 *        as well as the Transformation between Camera frame and
 *        Robot frame.
 */
class Distance {
 public:
  Distance();
  std::vector<Eigen::Vector4d> camToRobotTransform(
                                  std::vector<std::vector<double>> &camXYZ);
  std::vector<double> findDepth(std::vector<double> &boxHeight);
  std::vector<std::vector<double>> getXY(
                      std::vector<double> &depth, std::vector<cv::Rect> &r);
  int displayLocation(std::vector<Eigen::Vector4d> &locations,
                                                    std::string &frameInput);
  ~Distance();

 private:
  double avgHumanHeight = 175;
  double perceivedFy = 1028.57143;
  double perceivedFx = 1386.67;
  Eigen::Matrix4d poseMatrix;
};
