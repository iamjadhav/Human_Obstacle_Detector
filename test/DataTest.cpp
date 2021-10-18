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


TEST(Camera, Data_Input_Method) {
  Data camera;
  camera.getCamera(2);
  EXPECT_EQ(camera.frame.empty(), 1);
}

// TEST(Video, Data_Input_as_File) {
//   Data video;
//   std::string filename;
//   EXPECT_EQ(video.loadVideo(filename), 0);
// }

// TEST(Processing, If_Processed_Output) {
//   Data process;
//   cv::Mat frame;
//   frame = cv::imread("../Timeline.png");
//   cv::Mat resized = process.preProcessing(frame);
//   EXPECT_EQ(resized.rows, 200);
// }
