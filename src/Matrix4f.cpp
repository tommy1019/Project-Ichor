#include "Matrix4f.h"

const float* Matrix4f::operator[](int index) const
{
    return a[index];
}

float* Matrix4f::operator[](int index)
{
    return a[index];
}

inline Matrix4f Matrix4f::operator*(const Matrix4f &b) const
{
	Matrix4f c;
	for(int i = 0; i < 4; i++){
		for(int k = 0; k < 4; k++){
			c[k][i] = 0;
			for(int j = 0; j < 4; j++){
				c[k][i] = c[k][i] + a[j][i] * b[k][j];
			}
		}
	}
	return c;
}
