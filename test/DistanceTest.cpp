/**
 * @file DistanceTest.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Distance Class Tests
 * @version 0.1
 * @date 2021-10-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include "../include/Distance.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Test to verify if the correct tranformation is applied. 
 */
TEST(SIDistance, Tranform_check) {
  Distance dist;
  EXPECT_EQ(dist.camToRobotTransform(), 4);
}
