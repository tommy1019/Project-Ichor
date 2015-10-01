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
    int a[4][4] =
    {
        {1,0,0,0},
        {0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
    };
}

inline Matrix4f Matrix4f::operator*(const Matrix4f &b) const
{
	Matrix4f c;
	for(int i = 0; i < 4; i++){
		for(int k = 0; k < 4; k++){
			c[k][i] = a[0][i] * b[k][0] + a[1][i] * b[k][1] + a[2][i] * b[k][2] + a[3][i] * b[k][3]
		}
	}
	return c;
}
