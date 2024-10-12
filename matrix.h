#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct {
    double *data;
    int rows;
    int cols;
} Matrix;

Matrix create_rmatrix(int rows, int cols, int left, int right);
Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix *m);
void print_matrix(const Matrix *m);

#endif
