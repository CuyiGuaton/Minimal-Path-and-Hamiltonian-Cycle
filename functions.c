void mostrar(int **matrix, int order);
void incluir(int a, int b, int **matrix, int order);
void eliminar(int a, int b, int **matrix, int order);
int pertenece(int a, int b, int **matrix, int order);
int degreeVertex(int a, int **matrix, int order);
int imparV(int *impar, int **matrix, int order); //Guarda las aristas de grado impar en el arreglo impar y devuelve el largo de este arreglo.
int generator(int **matrix, int n,float p);

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


int generator(int **matrix, int n,float p) {
  int a;
  int b;

  //Da el orden de la matrix

  //Genera un grafo aleatorio
  for(a=0; a < n-1 ; a++){
    incluir(a,a+1,matrix,n);
    for(b=a+2 ; b<n ; b++)
      if( rand()%100 + 1 < p*100 )
        incluir(a,b,matrix,n);
  }
}
