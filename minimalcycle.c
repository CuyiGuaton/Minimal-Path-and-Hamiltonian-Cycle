#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

void findcycle(int row, int col, int vertex);
int isInCyle(int vertex, int num);
void recursive();
void copy();
int **graph;
int **graph2;
int **cycles;
int cyclesIndex=0;
int n;
int aux1;
int aux2;
int aux3;


int main(int argc, char const *argv[]) {

  n= atoi(argv[1]);

  //Esto crea la graph inmutable
  graph = (int **)malloc (n*sizeof(int *));
  for (int i=0;i<n;i++)
    graph[i] = (int *) malloc (n*sizeof(int *));

//Crea un grafo auxiliar modificable
  graph2 = (int **)malloc (n*sizeof(int *));
  for (int i=0;i<n;i++)
    graph2[i] = (int *) malloc (n*sizeof(int *));

  //grafo en el que se guardara cada cycle del grafo
  cycles = (int **)malloc (n*sizeof(int *));
  for (int i=0;i<n;i++){
    cycles[i] = (int *) malloc (n*sizeof(int *));
    for(int j=0 ; j<n; j++)
      cycles[i][j] = -1;
    }


  //Rellena la matriz
  generator(graph,n,atof(argv[2]));


  copy();
  mostrar(graph2,n);
  recursive();

  for( int i=0; i<n; i++ )
      free( graph[i] );
  free( graph );

  return 0;
}

void copy(){
  for(int i = 0; i<n; i++)
    for(int j=0;j<n;j++)
      graph2[i][j]= graph[i][j];
}

void recursive(){
  //findcycle(0,0,0);
  //copy();
  //cyclesIndex=0;
  //findcycle(1,0,1);
  for(int i= 0 ; i< n ; i++){
    findcycle(i,0,i);
    copy();
    cyclesIndex=0;
  }
  mostrar(cycles,n);

}

//verifica que ya se haya pasado por un vertice, devuelve 1 si lo esta
int isInCyle(int vertex, int num){
  for(int i = 0; i < n; i++)
    if( cycles[vertex][i] == num)
      return 1;
  return 0;
}

void findcycle(int row, int col, int vertex){
  if(col < n){
        if(isInCyle(vertex, row)==0){
            if(degreeVertex(row,graph2,n)<2){
              //retrocede
              cyclesIndex = cyclesIndex - 1;
              graph2[cycles[vertex][cyclesIndex]][row]=1;
              graph2[row][cycles[vertex][cyclesIndex]]=1;
              findcycle(cycles[vertex][cyclesIndex], row+1,vertex);
            }
            else
                if(graph2[row][col] == 0)
                  findcycle(row,col+1,vertex);
                else{
                  graph2[row][col] = 0;
                  graph2[col][row] = 0;
                  cycles[vertex][cyclesIndex] = row;
                  cyclesIndex = cyclesIndex +1;
                  findcycle(col,0,vertex);
                }
        }else{
          cycles[vertex][cyclesIndex] = row;
          cyclesIndex = cyclesIndex +1;
      }
    }
  }
