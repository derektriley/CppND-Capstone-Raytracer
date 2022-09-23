#include "World.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Constants.h"
#include "SingleSphere.h"
#include <iostream>

World::World() {
    background_color = black;
}

World::~World() {
    if (colors) {
        delete [] colors;
    }
}

void World::build() {
    vp.set_hres(600);
    vp.set_vres(600);
    vp.set_pixel_size(1.0);

    background_color = black;
    tracer_ptr = new SingleSphere(this);

    sphere.set_center(0.0, 0.0, 0.0);
    sphere.set_radius(85.0);

    colors = new RGBColor*[vp.vres];
    for (int i = 0; i < vp.vres; i++) {
        colors[i] = new RGBColor[vp.hres];
    }
}

void World::render_scene() {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0; // hard wired in origin z axis component
    double x, y;

    ray.d = Vector3D(0, 0, -1);

    // For each row of the image or up
    for (int r = 0; r < vp.vres; r++) {
        //For each column of the image or across
        for (int c = 0; c < vp.hres; c++) {
            ray.o = Point3D(vp.s * (c - vp.hres / 2.0 + 0.5), vp.s * (r - vp.vres / 2.0 + 0.5), zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_color);
        }
    }
}

void World::open_window(const int hres, const int vres) const {

}

void World::display_pixel(const int row, const int column, const RGBColor &pixel_color) {
    colors[row][column].r = pixel_color.r;
    colors[row][column].g = pixel_color.g;
    colors[row][column].b = pixel_color.b;
}