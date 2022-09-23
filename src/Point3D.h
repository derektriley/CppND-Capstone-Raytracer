#ifndef __POINT3D__
#define __POINT3D__

#include "Vector3D.h"

class Point3D {
    public:
        double x, y, z;

        Point3D(); // constructor
        Point3D(const double a); // constructor
        Point3D(const double a, const double b, const double c); //constructor
        Point3D(const Point3D& point); // copy constructor
        ~Point3D(); // desctructor


        Vector3D operator-(const Point3D& p) const; // Vector from point to point 
        Point3D operator+(const Vector3D& v) const;

};

inline Point3D Point3D::operator+(const Vector3D& v) const {
    return Point3D(x + v.z, y + v.y, z + v.z);
}

inline Vector3D Point3D::operator-(const Point3D& p) const {
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

#endif