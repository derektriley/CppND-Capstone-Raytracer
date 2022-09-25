#ifndef __GEOMETRICOBJECT__
#define __GEOMETRICOBJECT__
#include "ShadeRec.h"
#include "Ray.h"

class GeometricObject {

    public:
        RGBColor color;

        GeometricObject();
        GeometricObject(const GeometricObject& object);
        virtual ~GeometricObject();
        virtual bool hit(const Ray& ray, double &t, ShadeRec& s) const = 0;
        
    protected:
        GeometricObject& operator=(const GeometricObject &rhs);

};

#endif