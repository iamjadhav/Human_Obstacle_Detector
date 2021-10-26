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
 * @file Data.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Data Class Definition
 * @version 0.1
 * @date 2021-10-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Data.hpp"

/**
 * @brief Construct a new Data:: Data object
 */
Data::Data() {}

/**
 * @brief To take the camera frames as input
 * @param mode : Camera mode to view the camera or not
 * @return int
 */
double Data::getCamera(int mode, const std::string &test) {
  frame.release();
  double locx = 1;
  std::string frameInput = "camera";

  // sets the default camera for reading frames
  cv::VideoCapture cap(mode);
    if (cap.isOpened() == false && test == "OFF") {
      std::cout << "Camera cannot be opened! " << std::endl;
      return 3;
    } else if (test == "ON" || test == "OFF") {
        while (true) {
            // variable to store the camera frame X, Y, Z
            std::vector<std::vector<double>> coor;

            // variable to store the robot frame X, Y, Z
            std::vector<Eigen::Vector4d> finalLocations;

            // variable to store box heights
            std::vector<double> heights;

            // variable to store the estimated depths of humans
            std::vector<double> depths;

            std::vector<cv::Rect> box_coordinates;
            if (test == "OFF") {
              cap >> frame;
              } else if (test == "ON") {
              frame = cv::imread("../testdata/box_test.jpg");
              }
            if (frame.empty())
              break;

            // preprocessing the frame
            resizedFrame = preProcessing(frame);

            // detects the humans in the frame
            box_coordinates = human_detector.detectHuman(resizedFrame);
            heights = human_detector.putBox(resizedFrame, box_coordinates);
            depths = dist.findDepth(heights);

            // gets the camera frame x, y, z coordinates
            coor = dist.getXY(depths, box_coordinates);

            // if no humans detected continue
            if (coor.size() < 1 && test == "OFF") {
              cv::imshow("Detected Humans", resizedFrame);
              cv::waitKey(1);
              continue;
            }
            finalLocations = dist.camToRobotTransform(coor);
            dist.displayLocation(finalLocations, frameInput);
            if (test == "OFF") {
              cv::imshow("Detected Humans", resizedFrame);
              cv::waitKey(1);
              char q = static_cast<char> (cv::waitKey(25));
              locx = finalLocations[0][0]/1000;
              if (q == 27) {
                break;
              }
          } else {
              locx = finalLocations[0][0]/1000;
              break;
          }
        }
      cap.release();
      cv::destroyAllWindows();
    }
    return locx;
}

/**
 * @brief To take frames from a video file as input frames
 * @param filePath Path to the video file
 * @return double
 */
double Data::loadVideo(std::string filePath, const std::string &test) {
  frame.release();
  double locx = 1;
  cv::VideoCapture cap(2);
  std::string frameInput = "video";
  if (test == "OFF") {
    cv::VideoCapture cap1(filePath);
    cap = cap1;
  }
    if (cap.isOpened() == false && test == "OFF") {
      std::cout << "Video File cannot be opened! " << std::endl;
      return 3;
    } else if (test == "ON" || test == "OFF") {
        while (true) {
          // variable to store the camera frame X, Y, Z
          std::vector<std::vector<double>> coor;

          // variable to store the robot frame X, Y, Z
          std::vector<Eigen::Vector4d> finalLocations;

          // variable to store box heights
          std::vector<double> heights;

          // variable to store the estimated depths of humans
          std::vector<double> depths;

          std::vector<cv::Rect> box_coordinates;
          if (test == "OFF") {
            cap >> frame;
            } else if (test == "ON") {
            frame = cv::imread(filePath);
            }
          if (frame.empty())
            break;

          // preprocessing the frame
          resizedFrame = videoPreProcessing(frame);

          // detects the humans in the frame
          box_coordinates = human_detector.detectHuman(resizedFrame);
          heights = human_detector.putBox(resizedFrame, box_coordinates);
          depths = dist.findDepth(heights);

          // gets the camera frame x, y, z coordinates
          coor = dist.getXY(depths, box_coordinates);

          // if no humans detected continue
          if (coor.size() < 1 && test == "OFF") {
            cv::imshow("Detected Humans", resizedFrame);
            cv::waitKey(10);
            continue;
          }
          finalLocations = dist.camToRobotTransform(coor);
          dist.displayLocation(finalLocations, frameInput);
          if (test == "OFF") {
            cv::imshow("Detected Humans", resizedFrame);
            cv::waitKey(1);
            char q = static_cast<char> (cv::waitKey(25));
            locx = finalLocations[0][0]/1000;
            if (q == 27) {
              break;
            }
          } else {      // test case
              locx = finalLocations[0][0]/1000;
              break;
          }
        }
      cap.release();
      cv::destroyAllWindows();
    }
  return locx;
}

/**
 * @brief To resize and filter input images to operate on
 * @param frame : Frame to be preprocessed
 * @return cv::Mat
 */
cv::Mat Data::preProcessing(const cv::Mat &frame) {
  frame_copy = frame.clone();

  // resizing the frame
  cv::resize(frame_copy, resizedFrame, cv::Size(frame_copy.cols*2,
              frame_copy.rows*2));
  return resizedFrame;
}

/**
 * @brief To resize and filter input video frames to operate on
 * @param frame : Frame to be preprocessed
 * @return cv::Mat
 */
cv::Mat Data::videoPreProcessing(const cv::Mat &frame) {
  frame_copy = frame.clone();

  // resizing the frame
  cv::resize(frame_copy, resizedFrame, cv::Size((int)frame_copy.cols/2,
            (int)frame_copy.rows/2));
  return resizedFrame;
}

/**
 * @brief Destroy the Data:: Data object
 */
Data::~Data() {}
