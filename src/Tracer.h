#ifndef __TRACER__
#define __TRACER__

#include "Constants.h"
#include "Ray.h"
#include "RGBColor.h"
#include "World.h"

class Tracer {
    public:
        Tracer();
        Tracer(World* _world_ptr);

        virtual ~Tracer();
        virtual RGBColor trace_ray(const Ray& ray) const;
        virtual RGBColor trace_ray(const Ray ray, const int depth) const;

    protected:
        World* world_ptr;
};

#endif