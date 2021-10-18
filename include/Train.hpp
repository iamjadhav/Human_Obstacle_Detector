/**
 * @file Train.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Train Class Declaration
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Train class to train a custom model.
 */
class Train {
 public:
  Train();
  int trainSVMModel();
  cv::Mat dataPreProcessing();
  ~Train();

 private:
  std::vector<double> Weights;
  std::vector<double> labels;
};
