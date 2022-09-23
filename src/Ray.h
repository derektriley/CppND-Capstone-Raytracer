#ifndef __RAY__
#define __RAY__

#include "Point3D.h"
#include "Vector3D.h"

class Ray {
    public:

        Point3D o; // origin
        Vector3D d; // direction

        Ray(); // default constructor

        Ray (const Point3D &origin, const Vector3D &dir); // constructor

        Ray(const Ray& ray); // copy constructor

        Ray &operator=(const Ray &source); // assignment operator

        ~Ray(); // destructor
};

#endif