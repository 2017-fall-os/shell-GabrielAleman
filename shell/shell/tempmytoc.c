#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "mytoc.h"

/*int main(){
  char inputString [100];
  char ** array;
  read(0,inputString,100);
  int count = wordCounter(inputString);
  array = mytoc(inputString);
  printArray(inputString,array);  
  freeMem(inputString,array);
  
  return 0;
}
*/

int wordCounter(char * string,char delim){//works
  int counter = 0;
  int looper = 0;
  if((string[looper]!='\n') && string[looper] != delim){//needed to add first word ifs its the first on string
    counter++;
  }
  while(string[looper]!='\n'){
      if(string[looper] == delim){
      int temp = looper + 1;
      if(string[temp] != '\n' && string[temp] != delim){//checks for multiple spaces
	counter++;
      }
    }
    looper++;
  }
  return counter;
}

char ** mytoc(char * string,char delim){
  char ** wordArray;
  int words = wordCounter(string,delim);
  wordArray = malloc(words*sizeof(char *));
  wordArray = lengthOfWord(string,wordArray,delim);
  return wordArray;
}

void freeMem(char * string, char ** wordArray,char delim){
  int words = wordCounter(string,delim);
  int counter = 0;
   while(counter != words){
     printf("mem free %x %s\n",wordArray[counter],wordArray[counter]);
    free(wordArray[counter]);
    counter++;  
    }
  printf("mem free %x\n",wordArray);
  free(wordArray);
}

char ** lengthOfWord (char * string,char ** wordArray,char delim){//allocates memory for each word and places the word in the memeory
  int length = 0;
  int loop = 0;
  int wordStart = 0;
  int inserter = 0;
  
  while(string[loop] != '\n'){
    if(string[loop] != delim){
      length++;
    }
    else{
      if(length != 0){
	int temploop = 0;
	wordArray[inserter] = malloc(length+1);
	while(temploop != length){
	  wordArray[inserter][temploop] = string[wordStart];
	  temploop++;
	  wordStart++;
	}
	inserter++;
      }
      wordStart = loop+1;
      length = 0;
    }
    if(length != 0 && string[loop+1] == '\n'){
      int temploop = 0;
      wordArray[inserter] = malloc(length+1);
      while(temploop != length){
	wordArray[inserter][temploop] = string[wordStart];
	temploop++;
	wordStart++;
      }
      inserter++;     
    }
    loop++;
  }
  
  return wordArray;
}

 

void printArray(char * string, char ** wordArray,char delim){
  int words = wordCounter(string,delim);
  int counter = 0;
  while(counter != words){
    printf("%s mem location = %x\n",wordArray[counter],wordArray[counter]);
    counter++;
  }
}

