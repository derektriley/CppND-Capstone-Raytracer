#ifndef __WORLD__
#define __WORLD__

#include "ViewPlane.h"
#include "RGBColor.h"
#include "Constants.h"
#include "GeometricObject.h"
#include <fstream>
#include <vector>
#include <memory>

class Tracer;

class World {
    public:

        ViewPlane vp;
        RGBColor background_color;
        std::unique_ptr<Tracer> tracer_ptr;
        std::ofstream outputFile;
        std::vector<std::vector<std::unique_ptr<RGBColor>>> colors;
        std::vector<std::unique_ptr<GeometricObject>> objects;

        World(); // constructor

        ~World();

        void build();

        void render_scene(int lowRoxIdx, int highRowIdx);

        void open_window(const int hres, const int vres) const;

        void display_pixel(const int row, const int column, const RGBColor &pixel_color);

        void add_object(std::unique_ptr<GeometricObject> object);

        ShadeRec hit_bare_bones_objects(const Ray& ray);
};
#endif