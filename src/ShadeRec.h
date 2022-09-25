#ifndef __SHADEREC__
#define __SHADEREC__

class World;

#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGBColor.h"

class ShadeRec {
    public:
        bool hit_an_object;
        Point3D hit_point;
        Point3D local_hit_point;
        Normal normal;
        Ray ray;
        int depth;
        float t;
        World& w;
        RGBColor color;

        ShadeRec(World& wr);
        ShadeRec(const ShadeRec& sr);
};

#endif