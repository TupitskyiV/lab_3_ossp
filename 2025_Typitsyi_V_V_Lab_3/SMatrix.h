// ======= SMatrix.h =======
#ifndef __SMATRIX_H
#define __SMATRIX_H

#include <stddef.h> // ��� size_t

// ��������� �������
typedef struct Vector {
    double *Data;
    size_t VectorSize;
} SVector;

// ��������� �������
typedef struct Matrix {
    double **Data;
    size_t Row;
    size_t Col;
} SMatrix;

#endif // __SMATRIX_H

