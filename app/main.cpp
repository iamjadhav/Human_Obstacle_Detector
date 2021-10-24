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
#include "../include/Data.hpp"
#include "../include/Detect.hpp"
#include <opencv2/opencv.hpp>
#include <string>

int main() {
    char input;
    Data data;
    std::cout << "Do you want to detect humans using camera?(y/n)"
     << std::endl;
    std::cin >> input;
    if(input == 'y' || input == 'Y') {
      data.getCamera(0);
    } else if(input == 'n' || input == 'N'){
      std::cout << "Do you want to detect humans in a pre-recorded"
       << " video?(y/n)" << std::endl;
      std::cin >> input;
      if (input == 'y' || input == 'Y'){
        std::cout << "Enter the file path: \n";
        std::string path;
        std::cin >> path;
        data.loadVideo(path);
      } else {
        std::cout << "Sorry to see you go! \n";
      }
    }

    return 0;
}
