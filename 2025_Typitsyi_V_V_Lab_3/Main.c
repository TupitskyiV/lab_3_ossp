// ======= Main.c =======
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main() {
    printf("=== Start of Program ===\n");

    // === Вектори ===
    printf("\n--- Creating Vectors ---\n");
    SVector v1 = VectorCreate(3);
    SVector v2 = VectorCreate(3);
    if (!v1.Data || !v2.Data) {
        fprintf(stderr, "Error allocating vectors.\n");
        return 1;
    }

    // Ініціалізація векторів
    printf("Initializing vectors...\n");
    v1.Data[0] = 1; v1.Data[1] = 2; v1.Data[2] = 3;
    v2.Data[0] = 4; v2.Data[1] = 5; v2.Data[2] = 6;

    // Вивід векторів
    printf("\nVector 1: ");
    VectorDisplay(v1);
    printf("Vector 2: ");
    VectorDisplay(v2);

    // Додавання векторів
    printf("\n--- Vector Addition ---\n");
    SVector vAdd = VectorAdd(v1, v2);
    printf("Vector Add Result: ");
    VectorDisplay(vAdd);

    // Різниця векторів
    printf("\n--- Vector Subtraction ---\n");
    SVector vDiff = VectorDiff(v1, v2);
    printf("Vector Diff Result: ");
    VectorDisplay(vDiff);

    // Скалярний добуток
    printf("\n--- Scalar Product ---\n");
    double scalar = VectorScalar(v1, v2);
    printf("Scalar Product Result: %g\n", scalar);

    // Множення вектора на константу
    printf("\n--- Vector Multiply by Constant ---\n");
    SVector vMul = VectorMultConst(v1, 2.0);
    printf("v1 * 2: ");
    VectorDisplay(vMul);

    // Копіювання вектора
    printf("\n--- Copy Vector ---\n");
    SVector vCopy = VectorCopy(v2);
    printf("Copy of v2: ");
    VectorDisplay(vCopy);

    // Звільнення памʼяті для векторів
    printf("\n--- Deleting Vectors ---\n");
    VectorDelete(&v1);
    VectorDelete(&v2);
    VectorDelete(&vAdd);
    VectorDelete(&vDiff);
    VectorDelete(&vMul);
    VectorDelete(&vCopy);

    // === Матриці ===
    printf("\n--- Creating Matrices ---\n");
    SMatrix m1 = MatrixCreate(2, 2);
    SMatrix m2 = MatrixCreate(2, 2);
    if (!m1.Data || !m2.Data) {
        fprintf(stderr, "Error allocating matrices.\n");
        return 1;
    }

    // Ініціалізація матриць
    printf("Initializing matrices...\n");
    m1.Data[0][0] = 1; m1.Data[0][1] = 2;
    m1.Data[1][0] = 3; m1.Data[1][1] = 4;

    m2.Data[0][0] = 5; m2.Data[0][1] = 6;
    m2.Data[1][0] = 7; m2.Data[1][1] = 8;

    // Вивід матриць
    printf("\nMatrix 1:\n");
    MatrixDisplay(m1);
    printf("Matrix 2:\n");
    MatrixDisplay(m2);

    // Додавання матриць
    printf("\n--- Matrix Addition ---\n");
    SMatrix mAdd = MatrixMMAdd(m1, m2);
    printf("Matrix Add Result:\n");
    MatrixDisplay(mAdd);

    // Множення матриць
    printf("\n--- Matrix Multiplication ---\n");
    SMatrix mMult = MatrixMMMult(m1, m2);
    printf("Matrix Multiply Result:\n");
    MatrixDisplay(mMult);

    // Перетворення матриці на одиничну
    printf("\n--- Converting Matrix 1 to Identity Matrix ---\n");
    MatrixMakeE(&m1);
    MatrixDisplay(m1);

    // Множення матриці на вектор
    printf("\n--- Matrix * Vector ---\n");
    SVector v3 = VectorCreate(2);
    if (!v3.Data) {
        fprintf(stderr, "Error allocating v3.\n");
        return 1;
    }
    v3.Data[0] = 1;
    v3.Data[1] = 2;

    SMatrix mVM = MatrixMVMult(m2, v3);
    printf("Matrix * Vector Result:\n");
    MatrixDisplay(mVM);

    // Звільнення памʼяті для матриць і векторів
    printf("\n--- Deleting Matrices and Vector ---\n");
    MatrixDelete(&m1);
    MatrixDelete(&m2);
    MatrixDelete(&mAdd);
    MatrixDelete(&mMult);
    MatrixDelete(&mVM);
    VectorDelete(&v3);

    printf("\n=== End of Program ===\n");
    return 0;
}
