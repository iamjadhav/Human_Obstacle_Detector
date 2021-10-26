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
 * @file main.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Human Obstacle Detector
 * @version 0.1
 * @date 2021-10-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
#include "../include/Data.hpp"
#include "../include/Detect.hpp"
#include <opencv2/opencv.hpp>

// main
int main() {
    char input;

    // creatung data class object
    Data data;
    std::string test = "OFF";

    // takes input from user for which mode to run
    std::cout << "Do you want to detect humans using camera?(y/n)"
     << std::endl;
    std::cin >> input;

    // triggers camera mode
    if (input == 'y' || input == 'Y') {
      data.getCamera(0, test);
    } else if (input == 'n' || input == 'N') {    // triggers vidoe mode
      std::cout << "Do you want to detect humans in a pre-recorded"
       << " video?(y/n)" << std::endl;
      std::cin >> input;
      if (input == 'y' || input == 'Y') {
        std::cout << "Enter the file path: \n";
        std::string path;
        std::cin >> path;
        data.loadVideo(path, test);
      } else {
        std::cout << "Sorry to see you go! \n";
      }
    }
  return 0;
}
