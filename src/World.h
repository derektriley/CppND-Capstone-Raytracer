#ifndef __WORLD__
#define __WORLD__

#include "ViewPlane.h"
#include "RGBColor.h"
#include "Sphere.h"
#include "Constants.h"
#include <fstream>

class Tracer;

class World {
    public:

        ViewPlane vp;
        RGBColor background_color;
        Sphere sphere;
        Tracer* tracer_ptr;
        std::ofstream outputFile;
        RGBColor** colors;

        World(); // constructor

        ~World();

        void build();

        void render_scene();

        void open_window(const int hres, const int vres) const;

        void display_pixel(const int row, const int column, const RGBColor &pixel_color);
};
#endif