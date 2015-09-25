#include "Vector2f.h"

Vector2f::Vector2f()
{
    init(0,0);
}

Vector2f::Vector2f(float x, float y)
{
    init(x,y);
}

void Vector2f::init(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2f::length()
{
    return sqrt(x * x + y * y);
}

Vector2f Vector2f::operator+(const Vector2f &a)
{
    return Vector2f(x + a.x, y + a.y);
}

Vector2f Vector2f::operator-(const Vector2f &a)
{
    return Vector2f(x - a.x, y - a.y);
}

Vector2f Vector2f::operator*(const Vector2f &a)
{
    return Vector2f(x * a.x, y * a.y);
}

Vector2f Vector2f::operator/(const Vector2f &a)
{
    return Vector2f(x / a.x, y / a.y);
}
