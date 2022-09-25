#ifndef __MULTIOBJECT__
#define __MULTIOBJECT__

#include "Tracer.h"

class MultiObject : public Tracer {

    public:
        MultiObject();
        MultiObject(World* _worldPtr);
        virtual ~MultiObject();
        virtual RGBColor trace_ray(const Ray& ray) const;

};

#endif