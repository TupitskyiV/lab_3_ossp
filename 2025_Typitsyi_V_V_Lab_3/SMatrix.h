// ======= SMatrix.h =======
#ifndef __SMATRIX_H
#define __SMATRIX_H

#include <stddef.h> // Для size_t

// Структура вектора
typedef struct Vector {
    double *Data;
    size_t VectorSize;
} SVector;

// Структура матриці
typedef struct Matrix {
    double **Data;
    size_t Row;
    size_t Col;
} SMatrix;

#endif // __SMATRIX_H

