// ======= Matrix.h =======
#ifndef __MATRIX_H
#define __MATRIX_H

#include "SMatrix.h"

// Векторні функції
SVector VectorCreate(size_t size);
void VectorDisplay(const SVector v);
SVector VectorAdd(const SVector v1, const SVector v2);
SVector VectorDiff(const SVector v1, const SVector v2);
double VectorScalar(const SVector v1, const SVector v2);
SVector VectorMultConst(const SVector v, double c);
SVector VectorCopy(const SVector v);
void VectorDelete(SVector *v);

// Матричні функції
SMatrix MatrixCreate(size_t row, size_t col);
void MatrixDisplay(const SMatrix m);
void MatrixMakeE(SMatrix *m);
SMatrix MatrixMMMult(const SMatrix m1, const SMatrix m2);
SMatrix MatrixMMAdd(const SMatrix m1, const SMatrix m2);
SMatrix MatrixMVMult(const SMatrix m, const SVector v);
SMatrix MatrixCopy(const SMatrix m);
void MatrixDelete(SMatrix *m);

#endif // __MATRIX_H


