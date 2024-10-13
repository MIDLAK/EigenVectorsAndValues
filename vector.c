#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "vector.h"

Vector create_rvector(int size, int left, int right)
{
    Vector v = create_vector(size);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        v.data[i] = 
            (double)(rand() % (right - left +1) + left) + (double)rand()/RAND_MAX;

    return v;
}

Vector create_vector(int size) {
    return (Vector){.data = (double*)malloc(size*sizeof(double)), .size = size};
}

void free_vector(Vector *v)
{
    free(v->data);
    v->data = NULL;
}

void print_vector(Vector *v)
{
    for (int i = 0; i < v->size; i++)
        printf("%.2f ", v->data[i]);
}
