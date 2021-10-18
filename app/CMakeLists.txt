add_executable(shell-app main.cpp Data.cpp Detect.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}	
)
target_link_libraries (shell-app ${OpenCV_LIBS})
