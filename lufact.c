#include <lapacke.h>
#include "lufact.h"
#include "vector.h"

void lufact(Matrix *m, Vector *v)
{
    /* будет содержать информацию о перестановках */
    int *ipiv = (int*)malloc(m->rows * sizeof(int));

    LAPACKE_dgesv(
            LAPACK_ROW_MAJOR, 
            m->rows, 
            ONE_RIGHT_PART, 
            m->data, 
            m->cols, 
            ipiv, /* память освободится */
            v->data, 
            v->size 
    );
}
