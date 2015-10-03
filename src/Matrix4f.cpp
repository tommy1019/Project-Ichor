#include "Matrix4f.h"

const float* Matrix4f::operator[](int index) const
{
    return a[index];
}

float* Matrix4f::operator[](int index)
{
    return a[index];
}

void Matrix4f::initIdentity()
{
    a[0][0] = 1; a[0][1] = 0; a[0][2] = 0; a[0][3] = 0;
    a[1][0] = 0; a[1][1] = 1; a[1][2] = 0; a[1][3] = 0;
    a[2][0] = 0; a[2][1] = 0; a[2][2] = 1; a[2][3] = 0;
    a[3][0] = 0; a[3][1] = 0; a[3][2] = 0; a[3][3] = 1;
}

void Matrix4f::initTranslation(Vector3f m)
{
    a[0][0] = 1; a[0][1] = 0; a[0][2] = 0; a[0][3] = m.x;
    a[1][0] = 0; a[1][1] = 1; a[1][2] = 0; a[1][3] = m.y;
    a[2][0] = 0; a[2][1] = 0; a[2][2] = 1; a[2][3] = m.z;
    a[3][0] = 0; a[3][1] = 0; a[3][2] = 0; a[3][3] = 1;
}

void Matrix4f::initScale(Vector3f m)
{
    a[0][0] = m.x; a[0][1] = 0;   a[0][2] = 0;   a[0][3] = 0;
    a[1][0] = 0;   a[1][1] = m.y; a[1][2] = 0;   a[1][3] = 0;
    a[2][0] = 0;   a[2][1] = 0;   a[2][2] = m.z; a[2][3] = 0;
    a[3][0] = 0;   a[3][1] = 0;   a[3][2] = 0;   a[3][3] = 1;
}

