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

TEST(Box, Bounding_Box_Presence) {
  Detect box;
  cv::Mat frame;
  EXPECT_EQ(box.putBox(frame), 0);
}
