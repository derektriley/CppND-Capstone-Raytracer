#include <thread>
#include "World.h"
#include <boost/program_options.hpp>
#include <iostream>
#include "PPM.h"

/* Main function */
int main(int argc, char* argv[])
{
    boost::program_options::options_description desc("Usage: raytracer [options]\nAllowed Options");
    desc.add_options()
        ("help,h", "produce help message")
        ("threads,t", boost::program_options::value<int>(), "Set number of threads")
        ("output-file,o", boost::program_options::value<std::string>(), "Output file name");

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("threads")) {
        std::cout << "Number of threads set to " << vm["threads"].as<int>() << "\n";
    } else {
        std::cout << "Number of threads was not set. Defaulting to 1\n";
    }

    std::string fileName;
    if (vm.count("output-file")) {
        fileName = vm["output-file"].as<std::string>() + ".ppm";
        std::cout << "Opening file " << fileName << " for writing\n";
    } else {
        fileName = "raytrace.ppm";
        std::cout << "Opening file " << fileName << " for writing\n";
    }

    std::ofstream file;
    file.open(fileName);
    World w;
    w.outputFile = std::move(file);
    w.build();

    std::chrono::time_point t0 = std::chrono::high_resolution_clock::now();
    w.render_scene();
    std::chrono::time_point t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Render Time(ms): " << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "\n";

    //TODO Move to PPM?
    PPM::writeHeader(w.outputFile, w.vp.hres, w.vp.vres);
    PPM::writeImage(w.outputFile, w.colors, w.vp.hres, w.vp.vres);
    w.outputFile.close();
}