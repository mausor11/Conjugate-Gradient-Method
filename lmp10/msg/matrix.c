#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

matrix_t * make_matrix (int rn, int cn)
{
  matrix_t *new_mat = malloc (sizeof *new_mat);
  if (new_mat == NULL)
    return NULL;

  if ( (new_mat->e = malloc ((size_t) rn * (size_t) cn * sizeof (*new_mat->e) )) == NULL) {
    free (new_mat);
    return NULL;
  }
  new_mat->rn = rn;
  new_mat->cn = cn;
  memset (new_mat->e, 0, (size_t) (rn * (size_t) cn * sizeof *new_mat->e));
  return new_mat;
}

matrix_t * read_matrix (FILE * in)
{
  int rn, cn;
  int i, j;
  matrix_t *new_mat;
  if (fscanf (in, "%d %d", &rn, &cn) != 2)
    return NULL;

  if ((new_mat = make_matrix (rn, cn)) == NULL)
    return NULL;
  for (i = 0; i < rn; i++)
    for (j = 0; j < cn; j++)
      if (fscanf (in, "%lf", &new_mat->e[i * cn + j]) != 1) {
        
        return NULL;
      }

  return new_mat;
}

void write_matrix (matrix_t * m, FILE * out)
{
  int i, j;
  if (m == NULL) {
    fprintf (out, "Matrix is NULL\n");
    return;
  }

  fprintf (out, "%d %d\n", m->rn, m->cn);
  for (i = 0; i < m->rn; i++) {
    for (j = 0; j < m->cn - 1; j++)
      fprintf (out, "%8.5f ", m->e[i * m->cn + j]);
    fprintf (out, "%8.5f\n", m->e[i * m->cn + j]);
  }
}


matrix_t * transpose_matrix (matrix_t * s)
{
  matrix_t *d = NULL;
  if (s != NULL)
   // d = make_matrix (s->rn, s->cn);
    d = make_matrix (s->cn, s->rn);
  if (d != NULL) {
    int i, j;
    for (i = 0; i < s->rn; i++)
      for (j = 0; j < s->cn; j++)
        *(d->e + j * d->cn + i) = *(s->e + i * s->cn + j);
    /* d->rn= s->cn; d->cn= s->rn; done in make_matrix */
  }
  return d;
}

matrix_t * multiplication_matrix( matrix_t *a, matrix_t *b)
{
  
    matrix_t *wynik = make_matrix(a->rn,b->cn);
    int n = a->rn;
    int k = b->cn;
    for (int i = 0; i < n; i++)
        for (int p = 0; p < k; p++)
        {
                *(wynik->e + i*wynik->cn + p) = 0;
                
                for (int u = 0; u < b->rn; u++)
                    *(wynik->e + i*wynik->cn + p) = *(wynik->e + i*wynik->cn + p) + *(a->e + i*a->cn + u) * *(b->e + u*b->cn + p);
                    
        }
   
    return wynik;
}

matrix_t * multiplication_with_number_matrix( double v, matrix_t *a)
{
    
    matrix_t *tmp = make_matrix(a->rn,a->cn);
    double t;

    for(int i=0;i<a->rn;i++)
      for(int j=0;j<a->cn;j++)
      {
        t = a->e[i*a->cn + j];
        tmp->e[i*tmp->cn + j] = v*t;
       
      }
        
    
    return tmp;
}

matrix_t * negative_matrix(matrix_t *eqs){
  
    matrix_t *tmp = make_matrix(eqs->rn,eqs->cn);
    double t;
    for(int i=0;i<tmp->rn;i++) 
    {
      for(int j=0;j<tmp->cn;j++) 
      {
        t = eqs->e[i*eqs->cn + j];
        tmp->e[i*tmp->cn + j] = -t;
          
      }
    }
    
    return tmp;
}

matrix_t * sum_matrix(matrix_t *a, matrix_t *b)
{

    if(a->rn == b->rn && a->cn == b->cn)
    {
      
      int s=0;
      double r,t,y;
      matrix_t *tmp = make_matrix(a->rn, b->cn);
      
      for(int i=0;i<tmp->rn;i++)
        for(int j=0;j<tmp->cn;j++) {
        *(tmp->e + i*tmp->cn + j) = *(a->e + i*a->cn + j) + *(b->e + i*b->cn + j);
        //printf("%d. %lf = %lf + %lf\n", s++,*(tmp->e + i*tmp->cn + j), *(a->e + i*a->cn + j), *(b->e + i*b->cn + j));
        }
        return tmp;
    }
    else
    {
      return NULL;
    }
}
matrix_t * subtract_matrix(matrix_t *a, matrix_t *b)
{
    if(a->rn == b->rn && a->cn == b->cn)
    {
      matrix_t *tmp = make_matrix(a->rn, b->cn);

      for(int i=0;i<tmp->rn;i++)
        for(int j=0;j<tmp->cn;j++)
        *(tmp->e + i*tmp->cn + j) = *(a->e + i*a->cn + j) - *(b->e + i*b->cn + j);
        
      
        return tmp;
    }
    else
    {
      return NULL;
    }
}

void
add_to_entry_matrix (matrix_t * m, int i, int j, double val)
{
  if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
    m->e[i * m->cn + j] += val;
}

double
get_entry_matrix (matrix_t * m, int i, int j )
{
  if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
    return m->e[i * m->cn + j];
	else
		return -999;
}

void
free_matrix (matrix_t * m)
{
  
  free (m->e);
  free (m);
  
  
}

matrix_t *
copy_matrix (matrix_t * s)
{
  matrix_t *d = NULL;
  if (s != NULL)
    d = make_matrix (s->rn, s->cn);
  if (d != NULL) {
    memcpy (d->e, s->e, s->rn * s->cn * sizeof *s->e);
    /* int i;
       for( i= 0; i < s->rn*s->cn; i++ )
       *(d->e+i)= *(s->e+i);
     */
    /* d->rn= s->rn; d->cn= s->cn; done in make_matrix */
  }
  return d;
}