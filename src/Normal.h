#ifndef __NORMAL__
#define __NORMAL__

#include "Vector3D.h"
#include "Point3D.h"

class Normal {
    public:
        double x, y, z;

        Normal();
        Normal(double a);
        Normal(double _x, double _y, double _z);
        Normal(const Normal& n);
        Normal(const Vector3D& v);

        ~Normal();

        Normal& operator=(const Normal& rhs);
        Normal& operator=(const Vector3D& rhs);
        Normal& operator=(const Point3D& rhs);

        void normalize(); // convert normal to a unit normal

};


#endif