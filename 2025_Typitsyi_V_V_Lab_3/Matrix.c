// ======= Matrix.c =======
#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

// === ВЕКТОРИ ===

// Створення вектора заданого розміру
SVector VectorCreate(size_t size) {
    SVector v = {NULL, 0};
    if (size == 0) return v;

    v.Data = (double *)calloc(size, sizeof(double)); // виділення памʼяті
    if (v.Data == NULL) return v;

    v.VectorSize = size;
    return v;
}

// Виведення вектора на екран
void VectorDisplay(const SVector v) {
    if (v.Data == NULL || v.VectorSize == 0) {
        printf("Vector is empty or null.\n");
        return;
    }

    printf("vector[%zu] =", v.VectorSize);
    for (size_t i = 0; i < v.VectorSize; ++i) {
        printf(" %g", v.Data[i]);
    }
    printf("\n");
}

// Додавання двох векторів
SVector VectorAdd(const SVector v1, const SVector v2) {
    if (v1.VectorSize != v2.VectorSize || v1.Data == NULL || v2.Data == NULL)
        return (SVector){NULL, 0};

    SVector res = VectorCreate(v1.VectorSize);
    if (res.Data == NULL) return res;

    for (size_t i = 0; i < v1.VectorSize; ++i) {
        res.Data[i] = v1.Data[i] + v2.Data[i];
    }
    return res;
}

// Віднімання одного вектора від іншого
SVector VectorDiff(const SVector v1, const SVector v2) {
    if (v1.VectorSize != v2.VectorSize || v1.Data == NULL || v2.Data == NULL)
        return (SVector){NULL, 0};

    SVector res = VectorCreate(v1.VectorSize);
    if (res.Data == NULL) return res;

    for (size_t i = 0; i < v1.VectorSize; ++i) {
        res.Data[i] = v1.Data[i] - v2.Data[i];
    }
    return res;
}

// Скалярний добуток двох векторів
double VectorScalar(const SVector v1, const SVector v2) {
    if (v1.VectorSize != v2.VectorSize || v1.Data == NULL || v2.Data == NULL)
        return 0;

    double result = 0;
    for (size_t i = 0; i < v1.VectorSize; ++i) {
        result += v1.Data[i] * v2.Data[i];
    }
    return result;
}

// Множення вектора на константу
SVector VectorMultConst(const SVector v, double c) {
    if (v.Data == NULL || v.VectorSize == 0)
        return (SVector){NULL, 0};

    SVector res = VectorCreate(v.VectorSize);
    if (res.Data == NULL) return res;

    for (size_t i = 0; i < v.VectorSize; ++i) {
        res.Data[i] = v.Data[i] * c;
    }
    return res;
}

// Копіювання вектора
SVector VectorCopy(const SVector v) {
    if (v.Data == NULL || v.VectorSize == 0)
        return (SVector){NULL, 0};

    SVector copy = VectorCreate(v.VectorSize);
    if (copy.Data == NULL) return copy;

    for (size_t i = 0; i < v.VectorSize; ++i) {
        copy.Data[i] = v.Data[i];
    }
    return copy;
}

// Звільнення памʼяті для вектора
void VectorDelete(SVector *v) {
    if (v && v->Data) {
        free(v->Data);
        v->Data = NULL;
        v->VectorSize = 0;
    }
}

// === МАТРИЦІ ===

// Створення матриці розміром (row x col)
SMatrix MatrixCreate(size_t row, size_t col) {
    SMatrix m = {NULL, 0, 0};
    if (row == 0 || col == 0) return m;

    m.Data = (double **)malloc(row * sizeof(double *)); // виділення рядків
    if (m.Data == NULL) return m;

    for (size_t i = 0; i < row; ++i) {
        m.Data[i] = (double *)calloc(col, sizeof(double)); // виділення колонок
        if (m.Data[i] == NULL) {
            // звільнення памʼяті в разі помилки
            for (size_t j = 0; j < i; ++j) free(m.Data[j]);
            free(m.Data);
            m.Data = NULL;
            return (SMatrix){NULL, 0, 0};
        }
    }

    m.Row = row;
    m.Col = col;
    return m;
}

// Виведення матриці на екран
void MatrixDisplay(const SMatrix m) {
    if (m.Data == NULL || m.Row == 0 || m.Col == 0) {
        printf("Matrix is empty or null.\n");
        return;
    }

    for (size_t i = 0; i < m.Row; ++i) {
        for (size_t j = 0; j < m.Col; ++j) {
            printf("%g ", m.Data[i][j]);
        }
        printf("\n");
    }
}

// Перетворення матриці на одиничну (тільки квадратна!)
void MatrixMakeE(SMatrix *m) {
    if (m == NULL || m->Data == NULL || m->Row != m->Col) return;

    for (size_t i = 0; i < m->Row; ++i) {
        for (size_t j = 0; j < m->Col; ++j) {
            m->Data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

// Множення матриці на матрицю
SMatrix MatrixMMMult(const SMatrix m1, const SMatrix m2) {
    if (m1.Col != m2.Row || m1.Data == NULL || m2.Data == NULL)
        return (SMatrix){NULL, 0, 0};

    SMatrix res = MatrixCreate(m1.Row, m2.Col);
    if (res.Data == NULL) return res;

    for (size_t i = 0; i < m1.Row; ++i) {
        for (size_t j = 0; j < m2.Col; ++j) {
            for (size_t k = 0; k < m1.Col; ++k) {
                res.Data[i][j] += m1.Data[i][k] * m2.Data[k][j];
            }
        }
    }
    return res;
}

// Додавання двох матриць
SMatrix MatrixMMAdd(const SMatrix m1, const SMatrix m2) {
    if (m1.Row != m2.Row || m1.Col != m2.Col || m1.Data == NULL || m2.Data == NULL)
        return (SMatrix){NULL, 0, 0};

    SMatrix res = MatrixCreate(m1.Row, m1.Col);
    if (res.Data == NULL) return res;

    for (size_t i = 0; i < m1.Row; ++i) {
        for (size_t j = 0; j < m1.Col; ++j) {
            res.Data[i][j] = m1.Data[i][j] + m2.Data[i][j];
        }
    }
    return res;
}

// Множення матриці на вектор (дає матрицю-стовпець)
SMatrix MatrixMVMult(const SMatrix m, const SVector v) {
    if (m.Col != v.VectorSize || m.Data == NULL || v.Data == NULL)
        return (SMatrix){NULL, 0, 0};

    SMatrix res = MatrixCreate(m.Row, 1);
    if (res.Data == NULL) return res;

    for (size_t i = 0; i < m.Row; ++i) {
        for (size_t j = 0; j < m.Col; ++j) {
            res.Data[i][0] += m.Data[i][j] * v.Data[j];
        }
    }
    return res;
}

// Копіювання матриці
SMatrix MatrixCopy(const SMatrix m) {
    if (m.Data == NULL || m.Row == 0 || m.Col == 0)
        return (SMatrix){NULL, 0, 0};

    SMatrix copy = MatrixCreate(m.Row, m.Col);
    if (copy.Data == NULL) return copy;

    for (size_t i = 0; i < m.Row; ++i) {
        for (size_t j = 0; j < m.Col; ++j) {
            copy.Data[i][j] = m.Data[i][j];
        }
    }
    return copy;
}

// Звільнення памʼяті для матриці
void MatrixDelete(SMatrix *m) {
    if (m && m->Data) {
        for (size_t i = 0; i < m->Row; ++i) {
            free(m->Data[i]); // очищення кожного рядка
        }
        free(m->Data);       // очищення масиву вказівників
        m->Data = NULL;
        m->Row = 0;
        m->Col = 0;
    }
}
