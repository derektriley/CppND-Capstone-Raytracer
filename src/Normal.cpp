#include "Normal.h"
#include <cmath>

Normal::Normal() {}
Normal::Normal(double a) : x(a), y(a), z(a) {}
Normal::Normal(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
Normal::Normal(const Normal& n) : x(n.x), y(n.y), z(n.z) {}
Normal::Normal(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}

Normal::~Normal() {}

Normal& Normal::operator=(const Normal& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}
Normal& Normal::operator=(const Vector3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}
Normal& Normal::operator=(const Point3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

// convert normal to a unit normal
void Normal::normalize() {
    double length = std::sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;
} 