#include "MultiObject.h"

MultiObject::MultiObject() : Tracer() {};

MultiObject::MultiObject(World* _worldPtr) : Tracer(_worldPtr) {};

MultiObject::~MultiObject() {};

RGBColor MultiObject::trace_ray(const Ray& ray) const {
    ShadeRec sr = world_ptr->hit_bare_bones_objects(ray);
    if (sr.hit_an_object) {
        return sr.color;
    }
    return world_ptr->background_color;
};