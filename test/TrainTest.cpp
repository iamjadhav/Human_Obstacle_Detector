/**
 * @file TrainTest.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Train Class Tests
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include "../include/Train.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Test to verify if the model can be trained.
 */
TEST(TrainSVM, Training_model_or_not) {
  Train model;
  EXPECT_EQ(model.trainSVMModel(), 0);
}
