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
    a[0][0] = 1; a[1][0] = 0; a[2][0] = 0; a[3][0] = 0;
    a[0][1] = 0; a[1][1] = 1; a[2][1] = 0; a[3][1] = 0;
    a[0][2] = 0; a[1][2] = 0; a[2][2] = 1; a[3][2] = 0;
    a[0][3] = 0; a[1][3] = 0; a[2][3] = 0; a[3][3] = 1;
}

void Matrix4f::initTranslation(Vector3f m)
{
    a[0][0] = 1;  a[1][0] = 0;  a[2][0] = 0;  a[3][0] = m.x;
    a[0][1] = 0;  a[1][1] = 1;  a[2][1] = 0;  a[3][1] = m.y;
    a[0][2] = 0;  a[1][2] = 0;  a[2][2] = 1;  a[3][2] = m.z;
    a[0][3] = 0;  a[1][3] = 0;  a[2][3] = 0;  a[3][3] = 1;
}

void Matrix4f::initScale(Vector3f m)
{
    a[0][0] = m.x; a[1][0] = 0;   a[2][0] = 0;   a[3][0] = 0;
    a[0][1] = 0;   a[1][1] = m.y; a[2][1] = 0;   a[3][1] = 0;
    a[0][2] = 0;   a[1][2] = 0;   a[2][2] = m.z; a[3][2] = 0;
    a[0][3] = 0;   a[1][3] = 0;   a[2][3] = 0;   a[3][3] = 1;
}

void Matrix4f::initRotationD(Vector3f axis)
{
    initRotation(Vector3f(axis.x * M_PI / 180, axis.y * M_PI / 180, axis.z * M_PI / 180));
}

void Matrix4f::initRotation(Vector3f b)
{
    Matrix4f rx, ry, rz;

    rx.a[0][0] = 1; rx.a[1][0] = 0;         rx.a[2][0] = 0;             rx.a[3][0] = 0;
    rx.a[0][1] = 0; rx.a[1][1] = cosf(b.x); rx.a[2][1] = -sinf(b.x);    rx.a[3][1] = 0;
    rx.a[0][2] = 0; rx.a[1][2] = sinf(b.x); rx.a[2][2] = cosf(b.x);     rx.a[3][2] = 0;
    rx.a[0][3] = 0; rx.a[1][3] = 0;         rx.a[2][3] = 0;             rx.a[3][3] = 1;

    ry.a[0][0] = cosf(b.y); ry.a[1][0] = 0; ry.a[2][0] = -sinf(b.y);    ry.a[3][0] = 0;
    ry.a[0][1] = 0;         ry.a[1][1] = 1; ry.a[2][1] = 0;             ry.a[3][1] = 0;
    ry.a[0][2] = sinf(b.y); ry.a[1][2] = 0; ry.a[2][2] = cosf(b.y);     ry.a[3][2] = 0;
    ry.a[0][3] = 0;         ry.a[1][3] = 0; ry.a[2][3] = 0;             ry.a[3][3] = 1;

    rz.a[0][0] = cosf(b.z); rz.a[1][0] = -sinf(b.z);    rz.a[2][0] = 0; rz.a[3][0] = 0;
    rz.a[0][1] = sinf(b.z); rz.a[1][1] = cosf(b.z);     rz.a[2][1] = 0; rz.a[3][1] = 0;
    rz.a[0][2] = 0;         rz.a[1][2] = 0;             rz.a[2][2] = 1; rz.a[3][2] = 0;
    rz.a[0][3] = 0;         rz.a[1][3] = 0;             rz.a[2][3] = 0; rz.a[3][3] = 1;

    *this = rx * ry * rz;
}

void Matrix4f::initProjection(float width, float height, float fov, float near, float far)
{
    const float aR = height / width;
    const float zR = near - far;
    const float tF = 1 / tanf((fov / 2) * (M_PI / 360));

    a[0][0] = tF;   a[1][0] = 0;        a[2][0] = 0;                    a[3][0] = 0;
    a[0][1] = 0;    a[1][1] = tF /  aR; a[2][1] = 0;                    a[3][1] = 0;
    a[0][2] = 0;    a[1][2] = 0;        a[2][2] = (far + near) / zR;    a[3][2] = 2.0f * far * near / zR;
    a[0][3] = 0;    a[1][3] = 0;        a[2][3] = -1;                   a[3][3] = 0;

}
