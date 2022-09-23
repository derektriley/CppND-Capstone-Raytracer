#include "Point3D.h"

Point3D::Point3D() {}

Point3D::Point3D(const double a) : x(a), y(a), z(a) {} 

Point3D::Point3D(const double a, const double b, const double c) : x(a), y(b), z(c) {}

Point3D::Point3D(const Point3D& p) : x(p.x), y(p.y), z(p.z) {}

Point3D::~Point3D() {}

