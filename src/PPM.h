#ifndef __PPM__
#define __PPM__

#include <fstream>
#include "RGBColor.h"
#include <iostream>

/**
 * PPM file format definition from http://netpbm.sourceforge.net/doc/ppm.html
*/

#define PPM_MAGIC_NUMBER "P3"
#define PPM_MAX_COLOR_VALUE 255

class PPM {

    public:
        static void writeHeader(std::ofstream& outputFile, const int width, const int height);

        static void writeImage(std::ofstream& outputFile, RGBColor** colors, const int width, const int height);

};

void PPM::writeHeader(std::ofstream& outputFile, const int width, const int height) {
    if (!outputFile.is_open()) {
        std::cout << "Output file is not open. Exiting...\n";
    } else {
        outputFile << PPM_MAGIC_NUMBER << "\n";
        outputFile << width << "\n";
        outputFile << height << "\n";
        outputFile << PPM_MAX_COLOR_VALUE << "\n";
    }
};

void PPM::writeImage(std::ofstream& outputFile, RGBColor** colors, const int width, const int height) {
    if (!outputFile.is_open()) {
        std::cout << "Output file is not open. Exiting...\n";
    } else {
        // R G B
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                outputFile << static_cast<int>(colors[i][j].r * 255.0f) << " " 
                           << static_cast<int>(colors[i][j].g * 255.0f) << " " 
                           << static_cast<int>(colors[i][j].b * 255.0f) << "  ";
            }
            outputFile << "\n";
        }
    }
};

#endif