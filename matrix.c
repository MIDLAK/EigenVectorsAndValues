#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

Matrix create_rmatrix(int rows, int cols, int left, int right)
{
    Matrix m = create_matrix(rows, cols);

    srand(time(NULL));
    for (int i = 0; i < m.rows; i++) 
        for (int j = 0; j < m.cols; j++)
            m.data[i*cols+j] = 
                (double)(rand() % (right - left + 1) + left) + (double)rand()/RAND_MAX;

    return m;
}


Matrix create_matrix(int rows, int cols) {
    return (Matrix){
        .data = (double*)malloc(rows*cols*sizeof(double)),
        .cols = cols, 
        .rows = rows
    };
}

void free_matrix(Matrix *m)
{
    free(m->data);
    m->data = NULL;
}

void print_matrix(const Matrix *m)
{
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i*m->cols+j]);
        }
        printf("\n");
    }
}
