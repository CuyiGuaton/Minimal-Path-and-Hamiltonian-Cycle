#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"

int main(int argc, char const *argv[]) {
  int a;
  int b;
  int c;
  srand(time(NULL));

  //Da el orden de la matrix
  int n = atoi(argv[1]);
  float p = atof(argv[2]);

  //Esto crea la matrix
  int **matrix;
  matrix = (int **) malloc (n*sizeof(int *));
  for (int i=0;i<n;i++)
    matrix[i] = (int *) malloc (n*sizeof(int));

  //Genera un grafo aleatorio
  for(a=0; a < n-1 ; a++){
    incluir(a,a+1,matrix,n);
    for(b=a+2 ; b<n ; b++)
      if( rand()%100 + 1 < p*100 )
        incluir(a,b,matrix,n);
  }

mostrar(matrix,n);

Conex( a, b, matrix, n);

  for( int i=0; i<n; i++ ) {
      free( matrix[i] );
  }
  free( matrix );

  return 0;
}
