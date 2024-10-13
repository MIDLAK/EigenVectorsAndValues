#ifndef LUFACT_H
#define LUFACT_H

#include "vector.h"
#include "matrix.h"

#define ONE_RIGHT_PART 1 /* одно уравнение в правой части */

void lufact(Matrix *m, Vector *v);

#endif
