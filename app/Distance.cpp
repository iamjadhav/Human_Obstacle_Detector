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
 * @file Distance.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Distance Class Definition
 * @version 0.1
 * @date 2021-10-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Distance.hpp"


/**
 * @brief Construct a new Detect:: Detect object
 */
Distance::Distance() {}

/**
 * @brief Transformation between camera and robot frame
 * @param camXYZ : Camera frame X Y coordinates
 * @return std::vector<Eigen::Vector4d>
 */
std::vector<Eigen::Vector4d> Distance::camToRobotTransform(
                                    std::vector<std::vector<double>> &camXYZ) {
  // vector for storing robot frame coordinates
  std::vector<Eigen::Vector4d> locations;

  // transformation matrix between camera frame to robot frame
  poseMatrix << 1, 0, 0, 1,
                0, 1, 0, 2,
                0, 0, 1, 0,
                0, 0, 0, 1;
  Eigen::Vector4d robotXYZ;

  // iterates through camera frame coor and finally stores robot frame coor
  for (std::vector<double> i : camXYZ) {
    Eigen::Vector4d xyz(i[0], i[1], i[2], 1);
    robotXYZ << poseMatrix * xyz;
    locations.push_back(robotXYZ);
  }
  return locations;
}

/**
 * @brief Finds depth of the detected humans
 * @param boxHeight : contains the heights of all detected boxes
 * @return std::vector<double>
 */
std::vector<double> Distance::findDepth(std::vector<double> &boxHeight) {
  // stores the depth of humans detected
  std::vector<double> depth;

  // iterates through box heights and saves the depth of humans detected
  for (double i : boxHeight) {
    double tempDepth;
    tempDepth = (perceivedFy * avgHumanHeight)/(i/4);
    depth.push_back(tempDepth);
  }
  return depth;
}

/**
 * @brief Gets the X and Y coordinates w.r.t camera frame
 * @param depth : contains the estimated depth of detected humans
 * @param r : contains the detected boxes of humans
 * @return std::vector<std::vector<double>>
 */
std::vector<std::vector<double>> Distance::getXY(std::vector<double> &depth,
                                                  std::vector<cv::Rect> &r) {
  // vector of vectors for storing the camera frame x, Y, Z coordinates
  std::vector<std::vector<double>> worldCoordinates;

  // iterates through depths and box coordinates and computes world X, Y coor
  for (unsigned int i = 0; i < depth.size(); i++) {
    double X, Y, centx, centy;
    std::vector<double> xyzCoordinates;

    // cetroid of human in pixel coordinates
    centx = r[i].x + (r[i].width/2);
    centy = r[i].y + (r[i].height/2);

    // camera frame X  and Y coordinates
    X = ((640-centx)*(depth[i]))/(perceivedFx);
    Y = ((360-centy)*(depth[i]))/(perceivedFy);
    xyzCoordinates.push_back(X);
    xyzCoordinates.push_back(Y);
    xyzCoordinates.push_back(depth[i]);

    // storing the final camera frame coordinates
    worldCoordinates.push_back(xyzCoordinates);
  }
  return worldCoordinates;
}


/**
 * @brief To display the location of detected humans on-screen.
 * @param locations : contains human locations in robot reference frame
 * @param frameInput : contains the name of input type eg camera or video
 * @return int
 */
int Distance::displayLocation(std::vector<Eigen::Vector4d> &locations,
                              std::string &frameInput) {
  // variable to keep track of human ID's
  int id = 0;

  // iterates through the robot frame coordinates and displays location
  for (Eigen::Vector4d i : locations) {
    // lcation display mode for camera
    if (frameInput == "camera") {
      std::cout << "Detected human [" << id+1 << "] is located at (meters) \n"
                <<"X: " << std::setprecision(3) << i[0]/100 <<" Y: "<<
                 std::setprecision(3) << i[1]/100 <<" Depth: " <<
                 std::setprecision(3) << i[2]/100 << "\n\n";
    } else if (frameInput == "video") {      // lcation display mode for video
      std::cout << "Detected human [" << id+1 << "] is located at (meters) \n"
                <<"X: " << std::setprecision(3) << i[0]/1000 <<" Y: "<<
                 std::setprecision(3) << i[1]/1000 <<" Depth: " <<
                 std::setprecision(3) << i[2]/1000 << "\n\n";
    }
    id++;
  }
  return id;
}

/**
 * @brief Destroy the Distance:: Distance object
 */
Distance::~Distance() {}
