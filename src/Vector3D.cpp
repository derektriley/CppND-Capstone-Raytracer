#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"

Vector3D::Vector3D() {};

Vector3D::Vector3D(double a) {
    x = a;
    y = a;
    z = a;
}

Vector3D::Vector3D(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
}

Vector3D::Vector3D(const Vector3D& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

Vector3D::Vector3D(const Normal& n) {

}

Vector3D::Vector3D(const Point3D& p) : x(p.x), y(p.y), z(p.z) {};

Vector3D::~Vector3D() {};


