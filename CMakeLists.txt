cmake_minimum_required(VERSION 3.10)
project(BundleAdjustment)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Find Ceres
find_package(Ceres REQUIRED)

# Include directories for OpenCV and Ceres
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CERES_INCLUDE_DIRS})

# Add your source files
add_executable(BundleAdjustment bundle_adjustment_ceres.cpp common.cpp)

# Link Ceres and OpenCV libraries
target_link_libraries(BundleAdjustment ${CERES_LIBRARIES} ${OpenCV_LIBS})