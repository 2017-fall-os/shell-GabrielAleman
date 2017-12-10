#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mytoc.h"
char * spaceConverter(char * word);
char* concat(char *str1,char *str2);

int main(int args,char*argp[],char*envp[]){
  pid_t pid;
  int i;
  char * inputString =  malloc(50);
  char ** array;
  char ** inputArray;
  char ** arrayEnvp;
  int a;
  char * stringPath;
  char ** arrayPath;
  char ** EnvpHolder[50];//holds arrays of Envp to free memory later in the porgram
    
  for(a=0;envp[a] != (char*)0;a++){//gets the path and tokenized it
    arrayEnvp = mytoc(envp[a],'=');
    if(arrayEnvp[0][0]=='P' && arrayEnvp[0][1] == 'A'){
      arrayPath = mytoc(arrayEnvp[1],':');
      stringPath = arrayEnvp[1];
    }
    EnvpHolder[a]=arrayEnvp;
  }


  write(1,"$ ",2);
  read(0,inputString,40);
  inputArray = mytoc(inputString,' ');
  int temp = wordCounter(inputString,' ');
  char boolean = 'F';
  /*if(argp[1] == NULL){
    boolean = 'T';
  }*/
  for(a = 0; a != temp; a++){
    argp[a+1] = inputArray[a];
  }
  //if(boolean == 'T'){
  //write(1,"hi",2);
  //  argp[a+1] = "";
    //}
  //argp[a+1] = inputArray[a];
  // printf("%s\n",inputArray[1]);
  pid = fork();
  
  if(pid == 0){
    
    //if(argp[1] == NULL){
      //write(1,"No input\n",9);
      //}
     
    char * arg[] ={argp[1], argp[2], argp[3], argp[4], NULL};
    char * env[] = {NULL};
    int x = 0;
    x = execve(argp[1],arg,env);
    int y;
    int max = wordCounter(stringPath,':');
    for(y = 0; y != max; y++){
      char * temp = concat("/",argp[1]);
      char * string = concat(arrayPath[y],temp);
      char * arg[] ={string,argp[2],argp[3], NULL};
      x = execve(string,arg,env);
    }
    if(x=1){
      write(1,"command not found\n",18);
    }
  }
  else{
    wait(NULL);
    printf("hi");
    for(a=0;envp[a] != (char*)0;a++){
       freeMem(envp[a],EnvpHolder[a],'='); 
    }
    freeMem(stringPath,arrayPath,':');
    freeMem(inputString,inputArray,' ');
    write(1,"$ ",2);
    read(0,inputString,20);
     printf("hi\n");
    if(inputString[0]!='e' && inputString[1] != 'x' && inputString[2] != 'i'){
      char * arg[] = {"./shell", "ls" ,NULL};
      execve("./shell",arg,envp);
    }
    free(inputString);
    printf("this is parent\n");
  }
  
}


char * spaceConvert(char * word){
  int i = 0;
  while(word[i] != '\0' && word[i] != '\n'){
    if(word[i] == '_'){
      word[i] = ' ';
    }
    i++;
  }
  return word;
}


char * concat(char * str1, char * str2){//stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c i got that code from there
  char * result = malloc(strlen(str1)+strlen(str2)+1);
  strcpy(result,str1);
  strcat(result,str2);
  return result;
}
