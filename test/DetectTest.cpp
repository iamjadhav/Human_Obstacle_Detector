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
 * @brief Construct a new TEST object
 */
TEST(Bounding_box_test, checking_height) {
  Detect box;
  cv::Mat frame;
  frame = cv::imread("../testdata/box_test.jpg");
  box.detectHuman(frame);
  EXPECT_EQ(box.putBox(frame)[0], 483);
}
