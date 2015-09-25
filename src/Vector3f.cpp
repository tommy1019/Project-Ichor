#include "Vector3f.h"

Vector3f::Vector3f()
{
    init(0, 0, 0);
}

Vector3f::Vector3f(float x, float y, float z)
{
    init(x, y, z);
}

void Vector3f::init(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f Vector3f::normalized()
{
    float l = length();
    return Vector3f(x / l, y / l, z / l);
}

float Vector3f::length()
{
    return sqrt(x * x + y * y + z * z);
}

Vector3f Vector3f::operator+(const Vector3f &a)
{
    return Vector3f(x + a.x, y + a.y, z + a.z);
}

Vector3f Vector3f::operator-(const Vector3f &a)
{
    return Vector3f(x - a.x, y - a.y, z - a.z);
}

Vector3f Vector3f::operator*(const Vector3f &a)
{
    return Vector3f(x * a.x, y * a.y, z * a.z);
}

Vector3f Vector3f::operator/(const Vector3f &a)
{
    return Vector3f(x / a.x, y / a.y, z / a.z);
}
