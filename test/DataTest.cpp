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
  std::string test = "OFF";
  EXPECT_EQ(camera.getCamera(2, test), 3);
}

/**
 * @brief TEST to verify the main loop that call all the methods for camera
 */
TEST(Camera, Testing_Locations) {
  Data location;
  std::string test = "ON";
  EXPECT_NEAR(location.getCamera(2, test), -0.0255, 0.2);
}

/**
 * @brief Test to verify the video file does not exist and no frame is read
 */
TEST(Video, Data_Input_as_File_does_not_exist) {
  Data video;
  std::string filePath = "../67.webm";
  std::string test = "OFF";
  EXPECT_EQ(video.loadVideo(filePath, test), 3);
}

/**
 * @brief TEST to verify the main loop that call all the methods for video
 */
TEST(Video, Testing_Locations) {
  Data location;
  std::string test = "ON";
  EXPECT_NEAR(location.loadVideo("../testdata/box_test.jpg", test), 1.07, 0.2);
}


/**
 * @brief Test to verify the number of rows after preprocessing
 */
TEST(Processing, Processed_Image_Rows) {
  Data process;
  cv::Mat frame;
  frame = cv::imread("../testdata/Timeline.png");
  cv::Mat resized = process.preProcessing(frame);
  EXPECT_EQ(resized.rows, (frame.rows*2));
}

/**
 * @brief Test to verify the number of columns after preprocessing
 */
TEST(Video_Processing, Processed_Video_frame_Columns) {
  Data process;
  cv::Mat frame;
  frame = cv::imread("../testdata/Timeline.png");
  cv::Mat resized = process.videoPreProcessing(frame);
  EXPECT_EQ(resized.cols, (frame.cols/2));
}
