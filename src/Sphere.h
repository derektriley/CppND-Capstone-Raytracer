#ifndef __SPHERE__
#define __SPHERE__

#include "GeometricObject.h"
#include "Point3D.h"
#include "Ray.h"
#include "ShadeRec.h"

class Sphere : public GeometricObject {

    public:

        Sphere();
        Sphere(Point3D center, double r);
        Sphere(const Sphere& sphere);
        virtual ~Sphere();
        Sphere& operator=(const Sphere& sphere);
        void set_center(const Point3D& c);
        void set_center(const double x, const double y, const double z);
        void set_radius(const double r);
        virtual bool hit(const Ray& ray, double &t, ShadeRec& s) const;

    private:
        Point3D center;
        double radius;

};


inline void Sphere::set_center(const Point3D& c) {
    center = c;
}

inline void Sphere::set_center(const double x, const double y, const double z) {
    center.x = x;
    center.y = y;
    center.z = z;
}

inline void Sphere::set_radius(const double r) {
    radius = r;
}

#endif