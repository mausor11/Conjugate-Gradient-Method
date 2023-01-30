#ifndef _MSG_SOLVER_H_
#define _MSG_SOLVER_H_

#include "matrix.h"
#include <stdio.h>
#include <math.h>

int msg_solver_check( matrix_t *eqs, matrix_t *res);

int msg_solver(matrix_t *eqs,matrix_t *res);

double norm(matrix_t *eqs);



#endif
