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
 * @file Data.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Data Class Declaration
 * @version 0.1
 * @date 2021-10-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <Eigen/Dense>
#include <string>
#include <iostream>
#include "../include/Distance.hpp"
#include "../include/Detect.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Data class includes methods to get the input data
 *        and a method to put bounging boxes around the
 *        detected humans.
 *
 */
class Data {
 public:
  Data();
  Distance dist;
  Detect human_detector;
  cv::Mat frame;
  double getCamera(int mode, const std::string &test);
  double loadVideo(std::string filePath, const std::string &test);
  cv::Mat preProcessing(const cv::Mat &frame);
  cv::Mat videoPreProcessing(const cv::Mat &frame);
  ~Data();

 private:
  cv::Mat frame_copy;
  cv::Mat resizedFrame;
};
