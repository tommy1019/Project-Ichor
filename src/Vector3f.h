#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <math.h>

class Vector3f
{
    private:
        void init(float x, float y, float z);
    public:
        float x;
        float y;
        float z;

        Vector3f();
        Vector3f(float x, float y, float z);

        Vector3f normalized();
        float length();

        Vector3f operator+(const Vector3f &a);
        Vector3f operator-(const Vector3f &a);
        Vector3f operator*(const Vector3f &a);
        Vector3f operator/(const Vector3f &a);
};

#endif
