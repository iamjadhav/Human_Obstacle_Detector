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
 * @file Detect.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Detect Class Definition
 * @version 0.1
 * @date 2021-10-17
 *
 * @copyright Copyright (c) 2021
 *
 */


#include "../include/Detect.hpp"

/**
 * @brief Construct a new Detect:: Detect object
 */
Detect::Detect() {}

/**
 * @brief Method to detect humans in input frames
 * @param input_frame :Frame to detect humans
 * @return std::vector<double>
 */
std::vector<cv::Rect> Detect::detectHuman(cv::Mat &input_frame) {
  // sets default detector for detecting humans
  HOG.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

  // vector for storing the weights
  std::vector<double> weights;

  std::vector<cv::Rect> box_coordinates;

  // detects the humans in the frame
  HOG.detectMultiScale(input_frame, box_coordinates, weights);
  return box_coordinates;
}

/**
 * @brief Method to draw bouding boxes around detected humans
 * @param input_frame : Frame returned from detectHuman method
 * @return std::vector<double>
 */
std::vector<double> Detect::putBox(cv::Mat &input_frame,
                                    std::vector<cv::Rect> &box_coordinates) {
  // stores the heights of the boxes detected
  std::vector<double> heights;

  // iterates throught the box coordinates to draw boxes on the frame
  for ( size_t i = 0; i < box_coordinates.size(); i++ ) {
    cv::Rect r = box_coordinates[i];
    cv::rectangle(input_frame, r, cv::Scalar(0, 0, 255), 3);

    // adding ID to detected humans
    std::stringstream temp;
    temp << i + 1;
    cv::putText(input_frame, temp.str(), cv::Point(r.x, r.y+50),
                cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255) );
    heights.push_back(r.height);
  }
  return heights;
}

/**
 * @brief Destroy the Detect:: Detect object
 */
Detect::~Detect() {}
