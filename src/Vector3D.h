#ifndef __VECTOR3D__
#define __VECTOR3D__

class Normal;
class Point3D;

class Vector3D {
    public:
        double x, y, z;

        Vector3D();
        Vector3D(double a);
        Vector3D(double _x, double _y, double _z);
        Vector3D(const Vector3D& vec);
        Vector3D(const Normal& n);
        Vector3D(const Point3D& p);
        ~Vector3D();

        Vector3D& operator=(const Vector3D& rhs);
        double operator*(const Vector3D& b) const; 
        Vector3D operator*(const double a) const; 
        Vector3D operator+(const Vector3D& v) const;
        Vector3D operator/(const double a) const;
};

inline Vector3D operator*(const double a, const Vector3D& v) {
    return Vector3D(a * v.x, a * v.y, a * v.z);
};

inline Vector3D Vector3D::operator/(const double a) const {
    return Vector3D(x / a, y / a, z / a);
}

inline Vector3D& Vector3D::operator=(const Vector3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

inline double Vector3D::operator*(const Vector3D& b) const {
    return (x * b.x + y * b.y + z * b.z);
}

inline Vector3D Vector3D::operator*(const double a) const {
    return Vector3D(x * a, y * a, z * a);
}

inline Vector3D Vector3D::operator+(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

#endif