#ifndef __SINGLESPHERE_
#define __SINGLESPHERE_

#include "Tracer.h"

class SingleSphere : public Tracer {
    public:
        SingleSphere();
        SingleSphere(World* _worldPtr);
        virtual ~SingleSphere();
        virtual RGBColor trace_ray(const Ray& ray) const;
};

#endif