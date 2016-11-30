void mostrar(int **matrix, int order);
void incluir(int a, int b, int **matrix, int order);
void eliminar(int a, int b, int **matrix, int order);
int pertenece(int a, int b, int **matrix, int order);
int degreeVertex(int a, int **matrix, int order);
int imparV(int *impar, int **matrix, int order); //Guarda las aristas de grado impar en el arreglo impar y devuelve el largo de este arreglo.
void Conex(int a, int b, int **matrix, int order);

void mostrar(int **matrix, int order){
  for (int row=0; row<order; row++){
    for(int columns=0; columns<order; columns++)
         printf("%d ", matrix[row][columns]);
    printf("\n");
  }
  printf("\n");
}


void incluir(int a, int b, int **matrix, int order){
  matrix[a][b]= 1;
  matrix[b][a]=1;
}

void eliminar(int a, int b, int **matrix, int order){
  matrix[a][b]= 0;
  matrix[b][a]= 0;
}


//devueve 1 si pertenece, 0 sino.
int pertenece(int a, int b, int **matrix, int order){
  if(matrix[a][b] == 1)
    return 1;
  else
    return 0;
}

//Cuenta la cantidad de 1 en una fila, la cantidad total de 1 es el grado del vertice.
int degreeVertex(int a, int **matrix, int order){
    int count = 0;
    for( int c = 0; c < order; c++){
      if( matrix[a][c] == 1)
        count++;
    }
    return count;
}

//Guarda las aristas de grado impar en el arreglo impar y devuelve el largo de este arreglo.
int imparV(int *impar, int **matrix, int order){
  int degree;
  int count=0;
  for(int i = 0; i < order; i++){
    degree = degreeVertex(i,matrix,order);
    if(degree % 2 != 0){
      impar[count]=i;
      count++;
    }
  }
  return  count;
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


















