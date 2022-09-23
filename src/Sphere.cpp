#include "Sphere.h"
#include "Constants.h"
#include "ShadeRec.h"
#include "Vector3D.h"
#include <cmath>

Sphere::Sphere() : GeometricObject(), center(0.0), radius(1.0) {}

Sphere::Sphere(Point3D c, double r) : GeometricObject(), center(c), radius(r) {}

Sphere::Sphere(const Sphere& sphere) : GeometricObject(sphere), center(sphere.center), radius(sphere.radius) {}

Sphere::~Sphere()  {}

Sphere& Sphere::operator=(const Sphere& sphere) {
    // Guard against self assignment
    if (this == &sphere) {
        return (*this);
    }

    GeometricObject::operator=(sphere);

    center = sphere.center;
    radius = sphere.radius;
    return *this;
}

bool Sphere::hit(const Ray& ray, double &tmin, ShadeRec& sr) const {
    double t;
    Vector3D temp = ray.o - center;
    double a = ray.d * ray.d;
    double b = 2.0 * temp * ray.d;
    double c = temp * temp - radius * radius;
    double disc = b * b - 4.0 * a * c;

    if (disc < 0.0) {
        return false;
    } else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon) {
            tmin = t;
            sr.normal = (temp + t * ray.d) / radius;
            sr.local_hit_point = ray.o + t * ray.d;
            return true;
        }

        t = (-b + e) / denom; // larger root
        if (t > kEpsilon) {
            tmin = t;
            sr.normal = (temp + t * ray.d) / radius;
            sr.local_hit_point = ray.o + t * ray.d;
            return true;
        }
    }
    return false;
}