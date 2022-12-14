#include "Ray.h"

Ray::Ray() : o(0.0), d(0.0, 0.0, 1.0) {};

Ray::Ray(const Point3D &origin, const Vector3D &dir) : o(origin), d(dir) {}

Ray::Ray(const Ray& ray) : o(ray.o), d(ray.d) {}

Ray& Ray::operator=(const Ray &source) {
    o = source.o;
    d = source.d;
    return *this;
}

Ray::~Ray() {}