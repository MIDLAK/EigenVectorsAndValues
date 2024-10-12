#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    double *data;
    int size;
} Vector;

Vector create_rvector(int size, int left, int right);
Vector create_vector(int size);
void free_vector(Vector *v);
void print_vector(Vector *v);

#endif
