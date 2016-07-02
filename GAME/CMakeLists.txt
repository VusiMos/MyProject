cmake_minimum_required(VERSION 2.8)


# Enable debug symbols by default
# must be done before project() statement

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)


project(GAME1)


add_definitions(-std=c++14)

#Bring the headers
include_directories(include)

#can manually add the source files using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp ...etc)

#However,the file(GLOB..) allows for wildcard additions:

file(GLOB SOURCES "src/*.cpp")

# Define sources and executable
set(EXECUTABLE_NAME "GAME1")
add_executable(${EXECUTABLE_NAME} ${SOURCES})



# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${build})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2.1 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)





