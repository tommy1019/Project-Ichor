#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <math.h>

class Vector2f
{
    private:
	void init(float x, float y);
    public:
	float x;
	float y;

        Vector2f();
	Vector2f(float x,float y);

	float length();

	Vector2f operator+(const Vector2f &a);
	Vector2f operator-(const Vector2f &a);
	Vector2f operator*(const Vector2f &a);
	Vector2f operator/(const Vector2f &a);


};

#endif
