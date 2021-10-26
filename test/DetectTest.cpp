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
 * @file DetectTest.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Detect Class Tests
 * @version 0.1
 * @date 2021-10-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <gtest/gtest.h>
#include "../include/Detect.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Test to verify the size of the bounding box
 */
TEST(Detect_test, checking_detected_human) {
  Detect det;
  cv::Mat frame;
  unsigned int w = 1;
  frame = cv::imread("../testdata/box_test.jpg");
  EXPECT_EQ(det.detectHuman(frame).size(), w);
}

/**
 * @brief TEST to verify height of a bounding box
 */
TEST(Bounding_box_test, checking_height) {
  Detect box;
  cv::Mat frame;
  std::vector<cv::Rect> boxes;
  std::vector<double> heights;
  frame = cv::imread("../testdata/box_test.jpg");
  boxes = box.detectHuman(frame);
  heights = box.putBox(frame, boxes);
  EXPECT_EQ(heights[0], 483);
}
