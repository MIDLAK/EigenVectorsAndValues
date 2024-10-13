// gcc -o <outfile> *.c -llapacke -llapack -lblas
// если нужен cblas: gcc -o <outfile> *.c -I/usr/include/openblas -L/usr/lib -lopenblas 

#include <lapacke.h>
#include <stdio.h>
#include "matrix.h"
#include "eigen.h"
#include "vector.h"
#include "arithmetic.h"
#include "lufact.h"

int main() 
{
    Matrix m = create_rmatrix(3, 3, 1, 5);

    printf("МАТРИЦА:\n");
    print_matrix(&m);

    Eigen eigen = count_eigen(&m);

    printf("\nСОБСТВЕННЫЕ ЗНАЧЕНИЯ\nВещественные: (");
    print_vector(&eigen.rvalues);
    printf(")\nМнимые: (");
    print_vector(&eigen.ivalues);
    printf(")");

    printf("\n\nСОБСТВЕННЫЕ ВЕКТОРЫ\nПравые:\n");
    print_matrix(&eigen.rvectors);
    printf("Левые:\n");
    print_matrix(&eigen.lvectors);


    printf("\n\nУМНОЖЕНИЕ МАТРИЦЫ НА ВЕКТОР\nМатрица:\n");
    Matrix mulmat = create_rmatrix(3, 3, 1, 5);
    print_matrix(&mulmat);
    printf("Вектор: (");
    Vector mulvec = create_rvector(3, 1, 5);
    print_vector(&mulvec);
    printf(")\n");
    Vector mulres = multiply_matrix_vector(&mulmat, &mulvec);
    printf("Результат: (");
    print_vector(&mulres);
    printf(")");

    printf("\n\nСЛОЖЕНИЕ МАТРИЦЫ И ВЕКТОРА\nМатрица:\n");
    Matrix addmat = create_rmatrix(3, 3, 1, 5);
    print_matrix(&addmat);
    printf("Вектор: (");
    Vector addvec = create_rvector(3, 1, 5);
    print_vector(&addvec);
    printf(")\n");
    printf("Результат:\n");
    add_matrix_vector(&addmat, &addvec);
    print_matrix(&addmat);

    printf("\n\nВЫЧИТАНИЕ МАТРИЦЫ И ВЕКТОРА\nМатрица:\n");
    Matrix submat = create_rmatrix(3, 3, 1, 5);
    print_matrix(&submat);
    printf("Вектор: (");
    Vector subvec = create_rvector(3, 1, 5);
    print_vector(&subvec);
    printf(")\n");
    printf("Результат:\n");
    subtract_matrix_vector(&submat, &subvec);
    print_matrix(&submat);

    printf("\nLU-ФАКТОРИЗАЦИЯ\nМатрица A:\n");
    Matrix a = create_rmatrix(3, 3, 1, 5);
    print_matrix(&a);
    printf("Вектор b: (");
    Vector b = create_rvector(3, 1, 5);
    print_vector(&b);
    printf(")\n");
    printf("Вектор x: (");
    lufact(&a, &b);
    print_vector(&b);
    printf(")");

    return 0;
}
