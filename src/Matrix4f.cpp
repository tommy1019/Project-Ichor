#include "Matrix4f.h"

const float* Matrix4f::operator[](int index) const
{
    return a[index];
}

float* Matrix4f::operator[](int index)
{
    return a[index];
}

inline Matrix4f Matrix4f::operator*(const Matrix4f& right) const
{

}
