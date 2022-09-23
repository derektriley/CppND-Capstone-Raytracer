#include "World.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Constants.h"
#include "SingleSphere.h"

World::World() {
    background_color = black;
}

void World::build() {
    vp.set_hres(600);
    vp.set_vres(600);
    vp.set_pixel_size(1.0);

    background_color = black;
    tracer_ptr = new SingleSphere(this);

    sphere.set_center(0.0, 0.0, 0.0);
    sphere.set_radius(85.0);
}

void World::render_scene() const {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0; // hard wired in origin z axis component
    double x, y;

    ray.d = Vector3D(0, 0, -1);

    // For each row of the image or up
    for (int r = 0; r < vp.vres; r++) {
        //For each column of the image or across
        for (int c = 0; c <= vp.hres; c++) {
            x = vp.s * (c - 0.5 * (vp.hres - 1.0));
            y = vp.s * (r - 0.5 * (vp.vres - 1.0));
            ray.o = Point3D(x, y, zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_color);
        }
    }
}

void World::open_window(const int hres, const int vres) const {

}

void World::display_pixel(const int row, const int column, const RGBColor &pixel_color) const {

}