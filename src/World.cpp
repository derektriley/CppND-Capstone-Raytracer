#include "World.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Constants.h"
#include "MultiObject.h"
#include "ShadeRec.h"
#include "Sphere.h"
#include <iostream>
#include <memory>

World::World() {
    background_color = black;
}

World::~World() {
}

ShadeRec World::hit_bare_bones_objects(const Ray& ray) {
    ShadeRec sr(*this);
    double t;
    double tmin = kHugeValue;
    int num_objects = objects.size();

    for (int i = 0; i < num_objects; i++) {
        if (objects[i]->hit(ray, t, sr) && t < tmin) {
            sr.hit_an_object = true;
            tmin = t;
            sr.color = objects[i]->color;
        }
    }
    return sr;
}

void World::build() {
    vp.set_hres(1920);
    vp.set_vres(1080);
    vp.set_pixel_size(1.0);

    background_color = black;
    tracer_ptr = std::make_unique<MultiObject>(this);

    std::unique_ptr<Sphere> s1 = std::make_unique<Sphere>();
    s1->set_center(0.0, 0.0, 0.0);
    s1->set_radius(85.0);
    s1->color = RGBColor(red);

    std::unique_ptr<Sphere> s2 = std::make_unique<Sphere>();
    s2->set_center(-85.0, 0.0, 150.0);
    s2->set_radius(85.0);
    s2->color = RGBColor(0.0, 0.0, 1.0);

    add_object(std::move(s1));
    add_object(std::move(s2));

    colors.resize(vp.vres);
    for (int i = 0; i < vp.vres; i++) {
        for (int j = 0; j < vp.hres; j++) {
            colors[i].emplace_back(std::move(std::make_unique<RGBColor>(background_color)));
        }
    }
}

/**
 * @brief 
 * 
 * @param lowRoxIdx Starting row index
 * @param highRowIdx Ending row index
 */
void World::render_scene(int lowRoxIdx, int highRowIdx) {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0; // hard wired in origin z axis component
    double x, y;

    ray.d = Vector3D(0, 0, -1);

    // For each row of the image or up
    for (int r = lowRoxIdx; r < highRowIdx; r++) {
        //For each column of the image or across
        for (int c = 0; c < vp.hres; c++) {
            ray.o = Point3D(vp.s * (c - vp.hres / 2.0 + 0.5), vp.s * (r - vp.vres / 2.0 + 0.5), zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_color);
        }
    }
}

void World::add_object(std::unique_ptr<GeometricObject> object) {
    objects.emplace_back(std::move(object));
}

void World::open_window(const int hres, const int vres) const {

}

void World::display_pixel(const int row, const int column, const RGBColor &pixel_color) {
    colors[row][column]->r = pixel_color.r;
    colors[row][column]->g = pixel_color.g;
    colors[row][column]->b = pixel_color.b;
}