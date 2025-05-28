// ======= Matrix.c =======
#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

SVector VectorCreate(unsigned long int NumElement) {
    SVector v;
    v.VectorSize = NumElement;
    v.Data = calloc(NumElement, sizeof(double));
    return v;
}

void VectorDisplay(SVector v1) {
    unsigned long int i;
    printf("\nvector[%lu]=", v1.VectorSize);
    for(i = 0; i < v1.VectorSize; i++) {
        printf(" %g", v1.Data[i]);
    }
    printf("\n");
}

SVector VectorAdd(SVector v1, SVector v2) {
    SVector res = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        res.Data[i] = v1.Data[i] + v2.Data[i];
    }
    return res;
}

SVector VectorDiff(SVector v1, SVector v2) {
    SVector res = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        res.Data[i] = v1.Data[i] - v2.Data[i];
    }
    return res;
}

double VectorScalar(SVector v1, SVector v2) {
    double result = 0;
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        result += v1.Data[i] * v2.Data[i];
    }
    return result;
}

SVector VectorMultConst(SVector v1, double c) {
    SVector res = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        res.Data[i] = v1.Data[i] * c;
    }
    return res;
}

SVector VectorCopy(SVector v1) {
    SVector copy = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        copy.Data[i] = v1.Data[i];
    }
    return copy;
}

void VectorDelete(SVector *v1) {
    free(v1->Data);
    v1->Data = NULL;
    v1->VectorSize = 0;
}

SMatrix MatrixCreate(unsigned long int row, unsigned long int col) {
    SMatrix m;
    m.Row = row;
    m.Col = col;
    m.Data = malloc(row * sizeof(double*));
    for (unsigned long int i = 0; i < row; i++) {
        m.Data[i] = calloc(col, sizeof(double));
    }
    return m;
}

void MatrixDisplay(SMatrix m1) {
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            printf("%g ", m1.Data[i][j]);
        }
        printf("\n");
    }
}

void MatrixMakeE(SMatrix *m1) {
    for (unsigned long int i = 0; i < m1->Row; i++) {
        for (unsigned long int j = 0; j < m1->Col; j++) {
            m1->Data[i][j] = (i == j) ? 1 : 0;
        }
    }
}

SMatrix MatrixMMMult(SMatrix m1, SMatrix m2) {
    SMatrix res = MatrixCreate(m1.Row, m2.Col);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m2.Col; j++) {
            for (unsigned long int k = 0; k < m1.Col; k++) {
                res.Data[i][j] += m1.Data[i][k] * m2.Data[k][j];
            }
        }
    }
    return res;
}

SMatrix MatrixMMAdd(SMatrix m1, SMatrix m2) {
    SMatrix res = MatrixCreate(m1.Row, m1.Col);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            res.Data[i][j] = m1.Data[i][j] + m2.Data[i][j];
        }
    }
    return res;
}

SMatrix MatrixMVMult(SMatrix m1, SVector v1) {
    SMatrix res = MatrixCreate(m1.Row, 1);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            res.Data[i][0] += m1.Data[i][j] * v1.Data[j];
        }
    }
    return res;
}

SMatrix MatrixCopy(SMatrix m1) {
    SMatrix copy = MatrixCreate(m1.Row, m1.Col);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            copy.Data[i][j] = m1.Data[i][j];
        }
    }
    return copy;
}

void MatrixDelete(SMatrix *m1) {
    for (unsigned long int i = 0; i < m1->Row; i++) {
        free(m1->Data[i]);
    }
    free(m1->Data);
    m1->Data = NULL;
    m1->Row = 0;
    m1->Col = 0;
}
