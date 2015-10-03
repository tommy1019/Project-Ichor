#ifndef MATRIX_4F_H
#define MATRIX_4F_H

#include "Vector3f.h"

class Matrix4f
{
    public:
        float a[4][4];

        const float* operator[](int index) const;
        float* operator[](int index);

		void initIdentity();
        void initTranslation(Vector3f m);
        void initScale(Vector3f m);

        inline Matrix4f operator*(const Matrix4f& b) const
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
        };

};

#endif
