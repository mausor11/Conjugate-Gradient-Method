#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

typedef struct {
	int rn;
    int cn;
    double *e;
} matrix_t;

matrix_t * make_matrix( int rn, int cn );

matrix_t * read_matrix( FILE *in );

void write_matrix( matrix_t *, FILE *out );

matrix_t * transpose_matrix( matrix_t * s );

matrix_t * multiplication_matrix( matrix_t *a, matrix_t *b);

matrix_t * multiplication_with_number_matrix( double v, matrix_t *a);

matrix_t * negative_matrix(matrix_t *eqs);

matrix_t * sum_matrix(matrix_t *a, matrix_t *b);

matrix_t * subtract_matrix(matrix_t *a, matrix_t *b);

double get_entry_matrix( matrix_t *, int i, int j );

void add_to_entry_matrix( matrix_t *, int i, int j, double val );

void free_matrix (matrix_t * m);

matrix_t * copy_matrix( matrix_t *s );

#endif
