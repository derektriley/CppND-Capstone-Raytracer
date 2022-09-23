#include "Tracer.h"
#include "World.h"

Tracer::Tracer() {
    world_ptr == nullptr;
}

Tracer::Tracer(World* _world_ptr) : world_ptr(_world_ptr) {};

Tracer::~Tracer() {
    if (world_ptr)
        world_ptr == nullptr;
}

RGBColor Tracer::trace_ray(const Ray& ray) const {
    return black;
}

RGBColor Tracer::trace_ray(const Ray ray, const int depth) const {
    return black;
}
