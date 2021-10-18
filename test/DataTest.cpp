/**
 * @file DataTest.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Data Class Tests 
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include "../include/Data.hpp"
#include <opencv2/opencv.hpp>


TEST(Camera, Data_Input_Method) {
  Data camera;
  EXPECT_EQ(camera.getCamera(), 0);
}

TEST(Processing, If_Processed_Output) {
  Data process;
  cv::Mat frame;
  frame = process.loadVideo("../Timeline.png");
  EXPECT_EQ(process.preProcessing(frame), 100);
}
