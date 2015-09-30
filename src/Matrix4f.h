#ifndef MATRIX_4F_H
#define MATRIX_4F_H

class Matrix4f
{
    public:
        float a[4][4];

        const float* operator[](int index) const;
        float* operator[](int index);

        inline Matrix4f operator*(const Matrix4f &b) const;	
};

#endif
