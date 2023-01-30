#include "msg_solver.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int msg_solver_check( matrix_t *eqs, matrix_t *res)
{
    if(eqs != NULL) {
        if(msg_solver(eqs,res) == 0){
            return 0;
        }
        else
            return -1;  
    }
    else
        return 1;
}

int msg_solver( matrix_t *eqs, matrix_t *res)
{
    matrix_t *A = make_matrix(eqs->rn, eqs->cn - 1);
    matrix_t *b = make_matrix(eqs->rn, 1);

    for(int i=0;i<eqs->cn;i++) {
        for(int j=0;j<eqs->rn;j++) {
                if(i == eqs->cn-1)
                {
                    *(b->e + j) = *(eqs->e + (j+1)*i + j);
                }
                else
                {
                    *(A->e + i*A->cn + j) = *(eqs->e + i*eqs->cn + j);
                }

                    
        }

    }
    
    matrix_t *x = make_matrix(eqs->rn, 1);
    if(x == NULL)
        return -1;
    
    
    for(int i=0;i<x->rn;i++)
        x->e[i] = 0;
        

    matrix_t *p = make_matrix(eqs->rn, 1);
    matrix_t *r = make_matrix(eqs->rn, 1);
    matrix_t *tmp = make_matrix(1, eqs->rn);
        p = b;
        r = b;
    matrix_t *w = make_matrix(eqs->rn,1);
    w = r;
    matrix_t *z; //= make_matrix(eqs->rn,1);
    z = multiplication_matrix(A,p);

    matrix_t * top; //= make_matrix(1,1);
    matrix_t * bot; //= make_matrix(1,1);
    matrix_t *top_tmp2 = transpose_matrix(r);
    matrix_t *bot_tmp2 = transpose_matrix(p);
    top = multiplication_matrix( top_tmp2 , r); 
    bot = multiplication_matrix( bot_tmp2 , z); 
    free_matrix(top_tmp2);
    free_matrix(bot_tmp2);
    double g,d;
    g = *(top->e);
    d = *(bot->e);
    double alpha =  g/d;

    double beta;
    
    x = multiplication_with_number_matrix(alpha, p);
   


    for(int i=0;i<A->rn;i++) {
        matrix_t *tmp_r = multiplication_with_number_matrix(alpha,z);
        r = subtract_matrix(r, tmp_r );
        free_matrix(tmp_r);
    
        if(norm(r) < 1e-10 )
        {
            
            break;
        }
            
        
        matrix_t *tmp_top = transpose_matrix(r);
        matrix_t *tmp_bot = transpose_matrix(p);
        top = multiplication_matrix( tmp_top, r);
        bot = multiplication_matrix( tmp_bot, p);
        free_matrix(tmp_top);
        free_matrix(tmp_bot);

        g = *(top->e);
        d = *(bot->e);
        beta =  g/d;
        
        matrix_t *tmp_p = multiplication_with_number_matrix(beta,p);
        p  =sum_matrix( r, tmp_p );
        free_matrix(tmp_p);
        z = multiplication_matrix(A,p);    
        tmp_top = transpose_matrix(r);
        tmp_bot = transpose_matrix(p);
        top = multiplication_matrix( tmp_top, r); 
        bot = multiplication_matrix( tmp_bot, z);
        free_matrix(tmp_top);
        free_matrix(tmp_bot);

        g = *(top->e);
        d = *(bot->e);
        alpha =  g/d;
        matrix_t *x_tmp = multiplication_with_number_matrix(alpha,p);
 
        x = sum_matrix( x, x_tmp );
     
        free_matrix(x_tmp);
        
   
    }
    for(int i=0;i<x->rn;i++)
        res->e[i] = x->e[i];
    
    free_matrix(p);
    free_matrix(r);
    free_matrix(top);
    free_matrix(bot);
    free_matrix(z);
    free_matrix(x);
    free_matrix(w);
    free_matrix(A);
   
   
    
    return 0;

}

double norm(matrix_t *eqs)
{
	
    if(eqs!=NULL)
    {
    double result=0.0;
    matrix_t *tmp = eqs;

    for(int i=0;i<eqs->rn;i++)
        for(int j=0;j<eqs->cn;j++)
            result += tmp->e[j] * tmp->e[j];
    
    double n = sqrt(result);
    
    return n;
    }
    else
	    return -999;
}

