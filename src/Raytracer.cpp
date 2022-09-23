#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "World.h"

/* Main function */
int main()
{
    std::string _windowName = "Raytracer";
    /* Launch visualization */

    World w;
    w.build();
    w.render_scene();

    while (true)
    {
        // sleep at every iteration to reduce CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // Create a default img of 600, 600 pixels, Each Pixel Value 0 - 255 8-bit unsigned integer, Intial Color: Black
        cv::Mat img(600, 600, CV_8UC3, cv::Scalar(0, 0, 0));
        cv::imshow(_windowName, img);
        
        cv::waitKey(33);
    }
}