#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "vector.h"
#include "matrix.h"

#define ALPHA_NOT_SCALE 1.0   /* выполнить операцию без масштабирования */
#define BETA_ZERO_SCALE 0.0   /* обнуление начального вектора */
#define NORMAL_STRIDE   1     /* элементы в памяти идут последовательно */

Vector multiply_matrix_vector(Matrix *mat, Vector *vec);
void add_matrix_vector(Matrix *mat, Vector *vec);
void subtract_matrix_vector(Matrix *mat, Vector *vec);
void add_or_minus(Matrix *mat, Vector *vec, int alpha);

#endif
