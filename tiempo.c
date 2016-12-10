#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hamiltoncycle.c"

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  float t;
  clock_t tStart;
  printf("p t\n");
  for(float p = 0.00; p <= 1 ; p += 0.01 ){
      tStart = clock();
      cosa(n,p);
      t = (double)(clock() - tStart)/CLOCKS_PER_SEC;
      printf("\t %.2f \t %.6f \n",p, t );
      printf("\n");
    }
  return 0;

}
