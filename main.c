// gcc -o <outfile> *.c -llapacke -llapack -lblas
// если нужен cblas: gcc -o <outfile> *.c -I/usr/include/openblas -L/usr/lib -lopenblas 

#include <lapacke.h>
#include <stdio.h>
#include "matrix.h"
#include "eigen.h"
#include "vector.h"

int main() 
{
    Matrix m = create_rmatrix(3, 3, 1, 5);
    Eigen eigen = count_eigen(&m);

    printf("МАТРИЦА:\n");
    print_matrix(&m);

    printf("\nСОБСТВЕННЫЕ ЗНАЧЕНИЯ\nВещественные: (");
    print_vector(&eigen.rvalues);
    printf(")\nМнимые: (");
    print_vector(&eigen.ivalues);
    printf(")");

    printf("\n\nСОБСТВЕННЫЕ ВЕКТОРЫ\nПравые:\n");
    print_matrix(&eigen.rvectors);
    printf("Левые:\n");
    print_matrix(&eigen.lvectors);

    return 0;
}
