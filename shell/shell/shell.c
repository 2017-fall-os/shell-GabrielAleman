#include <unistd.h>
#include <stdio.h>
#include "mytoc.h"

void ex(char*a[],char*b[]);

int main(int args, char**argv,char**envp){
  char delim[1];
  char ** array;
  delim[1] = args[1][1];
  printf("...%d...",delim[1]);
}


void ex(char*a[],char*b[]){
  int as = 0;
  as = execve("./mytoc",a,b);
  printf("%i",as);
}
