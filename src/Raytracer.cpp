#include <thread>
#include "World.h"
#include <boost/program_options.hpp>
#include <iostream>
#include "PPM.h"
#include <vector>
#include <utility>
#include <thread>

/**
 * @brief Function to split a range into roughly n equal intervals for
 * parallel processing. Assumes n is <= hIdx
 * 
 * @param rows number of rows
 * @param n number of returned intervals
 * @return std::vector<std::pair<int,int>> 
 */
std::vector<std::pair<int,int>> chunk(int rows, int n) {
    std::vector<std::pair<int,int>> answer;
    if (n > rows) {
        answer.emplace_back(std::make_pair(0, rows));
        return answer;
    }
    int inc = (rows / n);
    int currentLowIdx = 0;
    int currentHighIdx = 0;
    for (int i = 0; i < n; i++) {
        currentLowIdx = currentHighIdx;
        if (currentHighIdx < rows - 1 && i == n - 1) {
            currentHighIdx = rows - 1;
        } else {
            currentHighIdx += inc;
        }
        answer.emplace_back(std::make_pair(currentLowIdx, currentHighIdx));
    }
    return answer;
}


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

    int numThreads = 1;
    if (vm.count("threads")) {
        std::cout << "Number of threads set to " << vm["threads"].as<int>() << "\n";
        numThreads = vm["threads"].as<int>();
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

    std::cout << "Splitting work into chunks...\n";
    std::vector<std::pair<int,int>> chunks = chunk(w.vp.vres, numThreads);
    for (int i = 0; i < chunks.size(); i++) {
        std::cout << "Chunk[" << i << "]: " << chunks[i].first << " " << chunks[i].second  << "\n";
    }

    std::chrono::time_point t0 = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;
    for (int i = 0; i < chunks.size(); i++) {
        threads.emplace_back(std::thread(&World::render_scene, &w, chunks[i].first, chunks[i].second));
    }
    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
    std::chrono::time_point t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Render Time(ms): " << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "\n";

    PPM::writeHeader(w.outputFile, w.vp.hres, w.vp.vres);
    PPM::writeImage(w.outputFile, std::move(w.colors), w.vp.hres, w.vp.vres);
    w.outputFile.close();
}