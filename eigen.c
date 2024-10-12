#include <lapacke.h>
#include "eigen.h"

Eigen count_eigen(Matrix *m)
{
    /* действительные и мнимые собственные значения */
    Vector wr = create_vector(m->rows);
    Vector wi = create_vector(m->rows);

    /* левый и правый собственные вектора */
    Matrix vr = create_matrix(m->rows, m->rows);
    Matrix vl = create_matrix(m->rows, m->rows);

    /* получение размера рабочего пространства */
    int info = LAPACKE_dgeev(
            LAPACK_ROW_MAJOR, // построковое хранение матрицы
            'V',              // вычислять левые и
            'V',              // правые собственные векторы
            m->rows,
            m->data,          
            m->cols,

            wr.data,           
            wi.data,          

            vl.data,
            vl.rows,
            vr.data,
            vr.rows
    );

    return (Eigen) {.rvalues = wr, .ivalues = wi, .rvectors = vr, .lvectors = vl};
}
