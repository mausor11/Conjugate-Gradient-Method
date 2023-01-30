#include "matrix.h"
#include "msg_solver.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{

    FILE *plik = fopen(argv[1], "r");
    matrix_t *eqs = read_matrix(plik);

    //write_matrix(eqs, stdout);
    //printf("\n");
    
    //int k = msg_solver(eqs);


    return 0;


}
