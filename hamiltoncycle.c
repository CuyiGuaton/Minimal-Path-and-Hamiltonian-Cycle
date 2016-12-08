#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"


//pico
void Conex(int a, int b, int **matrix, int order);
int suma_covex( int *suma , int n );

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

  printf("\n");
  generator(matrix,n,p);

  Conex( a, b, matrix, n);

  for( int i=0; i<n; i++ )
      free( matrix[i] );
  free( matrix );

  return 0;
}


int suma_covex( int *suma, int n )
{
	int convexo=1,column;printf(" \n " );
	for ( column = 0; column < n; column++ )
	{	
		if ( suma[column]!= 1 ){ convexo=0; }
	}

	return convexo;
}

void Conex(int a, int b, int **matrix, int n)
{	int row=0, column, *suma, *aux_row, *ciclo, cont=0, cont_min=0, i, j=0, u, h, count, count_min=0;

  	suma = (int *) malloc (n*sizeof(int));
	aux_row = (int *) malloc (n*sizeof(int));
	ciclo = (int *) malloc (n*sizeof(int));

	// Llenando Suma
	for ( column=0; column < n ; column++ )
	{
		suma[column]=0;	
		aux_row[column]=88;	
		ciclo[column]=88;
	}
	
	for ( column = 0; column < n; column++ )
	{	
//----------------------------------------------------------------------------------------------------------------------//
		if ( matrix[row][column]==1 && row!=column )
		{			
			suma[column] = 1;	suma[row] = 1;

			// Asignacion de filas 

			// Ver si la fila esta en espera/proseso
			for ( i=0 ; i < cont ; i++ )
			{
				if ( aux_row[i]==column ){ j=1; }
			}

			if ( j==0 )
			{	
				// Auxiliar
				aux_row[cont] = row;			cont++;		// Guarda los cambios de fila

				// Cambio de fila
				row = column;	

				column = 0;
			}
		
			// Ver ciclo minimo
			if ( cont > 2 )
			{
				for ( i=0 ; i <= (cont-2) ; i++ )
				{
					if ( aux_row[i]==column )
					{
						count= cont - i;

						if( count_min==0 || count_min > count ){ count_min=count; }
						if( count_min==count )
						{	
							u=0;
							for ( h=i ; h < cont ; h++ )
							{
								ciclo[u]=aux_row[h]; u++;
								if( h==cont-1 ){ ciclo[u]=row; u++; ciclo[u]=column;}
							}
						}
					}
				}
			}

			j=0;

			// Ciclo Hamilton
			if ( row==(n-1) && suma_covex( suma , n )==1 )
			{
				printf("Ciclo Hamiltoniano:  ");
				printf(" \n\n  ");
				for ( column = 0; column < n; column++ )
				{	
					if ( column!=(n-1) )
					{ 
						printf("%d ", aux_row[column] );	printf(" --> " );  
					}
					else
					{
						printf("%d ", row );	printf(" --> " );

						if ( matrix[(n-1)][0]==1 )
						{ 
							printf("%d ", 0 );
							printf("\n\n Tiene ciclo Hamilton\n" );
						}
						else
						{ 
							printf(" X "); 
							printf("\n\n No tiene ciclo Hamilton\n" );
						}
					}
				}
			}
		}

		if ( column == n-1 && cont!= 0 )
		{
			column = row;
			row = aux_row[cont];	cont--;	
			// Para evitar ciclo infinito
			if ( matrix[row][column]==1 ){ j=1; }
		}
	}


	if ( suma_covex( suma , n )==1 ){ printf("Es Conexa\n\n"); }else{ printf("No es Conexa\n\n"); printf("\n\n"); }

	printf (" Ciclo Minimo:\n \n ");
	for ( column = 0; column < count_min+2; column++ )
	{
		if( column < count_min+1 ){ printf(" %d ", ciclo[column] );	printf(" --> " );  }
		if( column==count_min+1 ){	printf(" %d ", ciclo[column] );	}
	}

	printf ("\n \n ");

	free( suma );
	free( aux_row );
	free( ciclo );
}






