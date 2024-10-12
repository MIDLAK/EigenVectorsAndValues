#ifndef EIGEN_H
#define EIGEN_H

#include "matrix.h"

typedef struct {
    Matrix rvectors; /* правые собственные векторы */
    Matrix lvectors; /* левые собственные векторы */

    Vector rvalues;  /* действительные собственные значения */
    Vector ivalues;  /* мнимые собственные значения */
} Eigen;

Eigen count_eigen(Matrix *m);

#endif
