#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"


void Conex(int a, int b, int **matrix, int order);


int main(int argc, char const *argv[]) {

  int a;
  int b;
  int n = atoi(argv[1]);
  float p = atof(argv[2]);

  //Esto crea la matrix
  int **matrix;
  matrix = (int **)malloc (n*sizeof(int *));
  for (int i=0;i<n;i++)
    matrix[i] = (int *) malloc (n*sizeof(int *));

  generator(matrix,n,p);

  Conex( a, b, matrix, n);

  for( int i=0; i<n; i++ )
      free( matrix[i] );
  free( matrix );

  return 0;
}

void Conex(int a, int b, int **matrix, int n)
{	int row=0, column, *suma, *aux_row, *aux_row_repetir, cont=0, cont_def=0, i, j=0;

  	suma = (int *) malloc (n*sizeof(int));
	aux_row = (int *) malloc (n*sizeof(int));
	aux_row_repetir = (int *) malloc (n*sizeof(int));

	// Llenando Suma
	for ( column=0; column < n ; column++ )
	{
		suma[column]=0;
		aux_row[column]=0;
		aux_row_repetir[column]=0;
	}

	for ( column = 0; column < n; column++ )
	{
		if ( matrix[row][column]==1 && row!=column )
		{
			suma[column] = 1;	suma[row] = 1;
			printf("j=");	printf("%d	", j );
			printf("column[");	printf("%d", column ); printf("]="); printf("%d	", suma[column] );
			// Asignacion de filas

			// Ver si la fila esta en espera
			for ( i=0 ; i <= cont ; i++ )
			{
				if ( aux_row[i]==column ){ j=1;	}
			}
			// Ver si una fila ya fue usada.
			for ( i=0 ; i < cont_def ; i++ )
			{
				if ( aux_row_repetir[i]==column ){ j=1;	}
			}
			if ( j==0 )
			{
				// Auxiliar
				aux_row[cont] = row;		cont++;	// Guarda los cambios de fila
				// Guardado
				aux_row_repetir[cont_def] = row;	cont_def++;	// Guarda los cambios de fila
				// Cambio de fila
				printf("column=");	printf("%d	", column ); printf("row="); printf("%d	", row );
				row = column;
				printf("	/	");
				column = 0;
				printf("column=");	printf("%d	", column ); printf("row="); printf("%d	", row );
			}

			j=0;

		}

		if ( column == n-1 && cont!= 0 )
		{
			column = row;
			row = aux_row[cont];	cont--;
			// Para evitar ciclo infinito
			if ( matrix[row][column]==1 ){ j=1; }
		}
	}

	j=0;printf("////");
	for ( column = 0; column < n; column++ )
	{
		if ( suma[column]!= 1 ){ j=1; }
		printf("column[");	printf("%d", column ); printf("]="); printf("%d	", suma[column] );
	}

	free( suma );
	free( aux_row );
	free( aux_row_repetir );

	if ( j==0 ){ printf("Es Conexa"); }else{ printf("No es Conexa"); printf("\n\n"); }
}
