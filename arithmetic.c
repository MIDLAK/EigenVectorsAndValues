#include <cblas.h>
#include "arithmetic.h"
#include "matrix.h"
#include "vector.h"

Vector multiply_matrix_vector(Matrix *mat, Vector *vec)
{
    Vector res = create_vector(vec->size);

    /* res = APLPHA_NOT_SCALE * mat * vec + BETA_ZERO_SCALE * res */
    cblas_dgemv(
            CblasRowMajor, /* формат хранения матрицы */
            CblasNoTrans,  /* матрица не транспонируется */
            mat->rows,
            mat->cols,
            ALPHA_NOT_SCALE,
            mat->data,
            mat->cols,
            vec->data,
            NORMAL_STRIDE,
            BETA_ZERO_SCALE,
            res.data,
            NORMAL_STRIDE 
    );

    return res;
}

void add_matrix_vector(Matrix *mat, Vector *vec) {
    add_or_minus(mat, vec, ALPHA_NOT_SCALE);
}

void subtract_matrix_vector(Matrix *mat, Vector *vec) {
    add_or_minus(mat, vec, -1 * ALPHA_NOT_SCALE);
}

void add_or_minus(Matrix *mat, Vector *vec, int alpha)
{
    for (int i = 0; i < vec->size; i++)
        cblas_daxpy(
                mat->rows,
                alpha,
                vec->data,
                NORMAL_STRIDE,
                &mat->data[i * mat->cols],
                NORMAL_STRIDE
        );
}
