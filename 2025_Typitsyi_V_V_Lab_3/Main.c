#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main() {
    printf("\nStart!\n");

    // Створення двох векторів
    SVector v1 = VectorCreate(3);
    SVector v2 = VectorCreate(3);

    // Ініціалізація
    v1.Data[0] = 1; v1.Data[1] = 2; v1.Data[2] = 3;
    v2.Data[0] = 4; v2.Data[1] = 5; v2.Data[2] = 6;

    // Вивід
    printf("\nVector 1: ");
    VectorDisplay(v1);
    printf("\nVector 2: ");
    VectorDisplay(v2);

    // Додавання
    SVector vAdd = VectorAdd(v1, v2);
    printf("\nVector Add: ");
    VectorDisplay(vAdd);

    // Різниця
    SVector vDiff = VectorDiff(v1, v2);
    printf("\nVector Diff: ");
    VectorDisplay(vDiff);

    // Скалярний добуток
    double scalar = VectorScalar(v1, v2);
    printf("\nScalar Product: %g\n", scalar);

    // Множення на константу
    SVector vMul = VectorMultConst(v1, 2.0);
    printf("\nVector v1 * 2: ");
    VectorDisplay(vMul);

    // Копія
    SVector vCopy = VectorCopy(v2);
    printf("\nCopy of v2: ");
    VectorDisplay(vCopy);

    // Звільнення памʼяті
    VectorDelete(&v1);
    VectorDelete(&v2);
    VectorDelete(&vAdd);
    VectorDelete(&vDiff);
    VectorDelete(&vMul);
    VectorDelete(&vCopy);

    // Матриці
    SMatrix m1 = MatrixCreate(2, 2);
    SMatrix m2 = MatrixCreate(2, 2);

    // Ініціалізація
    m1.Data[0][0] = 1; m1.Data[0][1] = 2;
    m1.Data[1][0] = 3; m1.Data[1][1] = 4;

    m2.Data[0][0] = 5; m2.Data[0][1] = 6;
    m2.Data[1][0] = 7; m2.Data[1][1] = 8;

    // Вивід
    printf("\nMatrix 1:\n");
    MatrixDisplay(m1);
    printf("Matrix 2:\n");
    MatrixDisplay(m2);

    // Додавання матриць
    SMatrix mAdd = MatrixMMAdd(m1, m2);
    printf("Matrix Add:\n");
    MatrixDisplay(mAdd);

    // Множення матриць
    SMatrix mMult = MatrixMMMult(m1, m2);
    printf("Matrix Multiply:\n");
    MatrixDisplay(mMult);

    // Одинична матриця
    MatrixMakeE(&m1);
    printf("Matrix 1 -> Identity:\n");
    MatrixDisplay(m1);

    // Вектор-матриця множення
    SVector v3 = VectorCreate(2);
    v3.Data[0] = 1;
    v3.Data[1] = 2;
    SMatrix mVM = MatrixMVMult(m2, v3);
    printf("Matrix * Vector:\n");
    MatrixDisplay(mVM);

    // Звільнення
    MatrixDelete(&m1);
    MatrixDelete(&m2);
    MatrixDelete(&mAdd);
    MatrixDelete(&mMult);
    MatrixDelete(&mVM);
    VectorDelete(&v3);

    printf("\nStoped!\n");

    system("pause"); // для Windows; або використай getchar();
    return 0;
}

