# CppND-Capstone-Raytracer
Simple Bare-bones Raytracer for C++ ND.

See https://en.wikipedia.org/wiki/Ray_tracing_(graphics) for general information on the concept of Raytracing.

Concepts and some object-oriented design taken from\
Ray Tracing from the Group Up
Book by Kevin Suffern

The raytracer program will produce a .PPM image file with a Blue and Red Sphere, with the Blue Sphere being closer to the camera. The image will be placed in the current directory named raytrace.ppm. You can specify a different output file name. See `-h`

## File and Class Structure
All the project's source and header files are located in the `/src` directory. The class structure is object oriented.

`Raytracer.cpp` contains the `main()` method for the application. This will handle command line argument processing and chunking the work for multi-threading if specified.

Objects like `Sphere` inherit from `GeometricObject` which allows the raytracer to be flexible for future object definitons.

`World` contains a `Tracer` which can be inherited by other classes such as `MultiObject` which can handle tracing rays for multiple objects in the scene. This allows for extension later.

In terms of the math required for the Raytracer, classes `Vector3D`, `Point3D` are the most relevent in the project's current state. There has been many operators overloaded to aid in the simplification of math for ray-object intersections.

`PPM` This class handles writing `RGBColor` instances to the ppm file format specification.


## Expected Program Behavior

The Raytracer should produce the following image:
![Raytrace Image](/example/Example_Output.png "Image")

### Running with 1 Thread (default)

<code>~/CppND-Capstone-Raytracer/build$ ./raytracer -t 1\
Number of threads set to 1\
Opening file raytrace.ppm for writing\
Splitting work into chunks...\
Chunk[0]: 0 1079\
Render Time(ms): 447</code>

### Running with n Threads (-t)
<code>~/CppND-Capstone-Raytracer/build$ ./raytracer -t 8\
Number of threads set to 8\
Opening file raytrace.ppm for writing\
Splitting work into chunks...\
Chunk[0]: 0 135\
Chunk[1]: 135 270\
Chunk[2]: 270 405\
Chunk[3]: 405 540\
Chunk[4]: 540 675\
Chunk[5]: 675 810\
Chunk[6]: 810 945\
Chunk[7]: 945 1079\
Render Time(ms): 68</code>

### Expected Image Result

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* Boost >= 1.58
  * The Boost 1.80.0 source code can be found [here](https://boostorg.jfrog.io/artifactory/main/release/1.80.0/source/)
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
Many of the project rubric criteria was met and I have listed out some criteria that has been met by this project.

1. **The project reads data from a file and process the data, or the program writes data to a file.**\
`PPM.h::36` The raytracer write a image of file format PPM, PPM.h contains the methods for writing to a file.

2. **The project accepts user input and processes the input.**\
`Raytracer.cpp::34` The project accpets input via command line arguments via Boost's program_arguments component and performs processing on them to use in the raytracer.

3. **The project uses Object Oriented Programming techniques.**\
`GeometricObject.h` is a base class for `Sphere.h`

4. **Classes use appropriate access specifiers for class members.**\
Most class members are public in order to allow for easier definition of mathmatical functions like ray geometric object intersections. 

5. **Class constructors utilize member intialization lists.**\
Most classes use intialization lists for their constructors. See `Vector3D.h::29`

6. **Classes follow an appropriate inheritance hierarchy.**\
`GeometricObject.h` is a base class for `Sphere.h`\
`Tracer.h` is a base class for `MultiObject.h`

7. **Derived class functions override virtual base class functions.**\
See `GeometricObject.h::14` for the hit function which is overwritten by classes which inherit from GeometricObject.

8. **The project uses smart pointers instead of raw pointers.**\
See `World.h` for the use of smart pointers intead of raw pointers for the RGBColor's per pixel and GeometricObjects.

9. **The project uses multithreading.**\
See `Raytracer.cpp::89` for the use of `std::thread` the rows of the image are chunked into roughly equal intervals for processing  