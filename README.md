# CppND-Capstone-Raytracer
Simple Bare-bones Raytracer for C++ ND.

See https://en.wikipedia.org/wiki/Ray_tracing_(graphics) for general information on the concept of Raytracing.

Concepts and some object-oriented design taken from
Ray Tracing from the Group Up
Book by Kevin Suffern


## File and Class Structure


## Expected Program Behavior


## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools

Indicate file and class structure, along with expected behavior or ouput of the program

Indicate which rubric points are addressed. List files and line numbers that rubric points are addressed. to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* Boost >= 1.74
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./raytracer`.
5. Run: `./raytracer -h`. To view help options.

## Project Rubric Crtiteria
Many of the project rubric criteria was met and I have listed out 10 criteria that has been met by this project.

1. **The project reads data from a file and process the data, or the program writes data to a file.**
The raytracer write a image of file format PPM, PPM.h contains the methods for writing to a file.

2. **The project accepts user input and processes the input.** The project accpets input via command line arguments via Boost's program_arguments component and performs processing on them to use in the raytracer.

3. **The project uses Object Oriented Programming techniques.**

4. **Classes use appropriate access specifiers for class members.**

5. **Class constructors utilize member intialization lists.**

6. **Classes follow an appropriate inheritance hierarchy.**

7. **Derived class functions override virtual base class functions.**

8. **The project uses smart pointers instead of raw pointers.**

9. **The project uses multithreading.**

10. **A promise and a future is used in the project.**