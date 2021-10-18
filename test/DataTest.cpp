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
#include <string>
#include "../include/Data.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Test to validate if the camera cannot be opened 
 */
TEST(Camera, Data_Input_Method_camera_works) {
  Data camera;
  camera.getCamera(2);
  EXPECT_EQ(camera.frame.empty(), 1);
}

/**
 * @brief Test to verify the video file does not exist and no frame is read
 */
TEST(Video, Data_Input_as_File_does_not_exist) {
  Data video;
  std::string filename;
  EXPECT_EQ(video.frame.empty(), 1);
}

/**
 * @brief Test to verify the number of rows after preprocessing 
 */
TEST(Processing, Processed_Image_Rows) {
  Data process;
  cv::Mat frame;
  frame = cv::imread("../Timeline.png");
  cv::Mat resized = process.preProcessing(frame);
  EXPECT_EQ(resized.rows, (frame.rows*2));
}
