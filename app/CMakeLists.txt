add_executable(shell-app main.cpp Data.cpp Detect.cpp Distance.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR}
)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
target_link_libraries(shell-app ${OpenCV_LIBS} ${EIGEN3_LIBS})
