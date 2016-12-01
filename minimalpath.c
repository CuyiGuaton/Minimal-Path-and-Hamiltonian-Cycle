#include <stdio.h>
#include <stdlib.h>


void mostrar(int **matrix, int order){
  for (int row=0; row<order; row++){
    for(int columns=0; columns<order; columns++)
         printf("%d ", matrix[row][columns]);
    printf("\n");
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);

  //Esto crea la matrix
  int **matrix;
  matrix = (int **)malloc (n*sizeof(int *));
  for (int i=0;i<n;i++)
    matrix[i] = (int *) calloc (n,sizeof(int *));

  mostrar(matrix,n);

  for( int i=0; i<n; i++ )
      free( matrix[i] );
  free( matrix );

  return 0;
}
