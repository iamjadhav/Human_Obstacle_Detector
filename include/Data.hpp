/**
 * @file data.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Data class includes methods to get the input data
 *        and a method to put bounging boxes around the 
 *        detected humans. 
 */
class Data {
 public:
Data();
int getCamera();
cv::Mat loadVideo(std::string filePath);
int preProcessing(const cv::Mat &frame);
~Data();
 private:
cv::Mat frame;
cv::Mat frame_copy;
cv::Mat resizedFrame;
};
