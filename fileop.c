#include "fileop.h"



size_t filelen(FILE* file){
  fseek(file,0,SEEK_END);
  size_t len = ftell(file);
  fseek(file,0,SEEK_SET);
  return len;
}

char* openfile(char* name){
  FILE* filep = fopen(name,"r");
  size_t flen = filelen(filep);
  char* buffer = (char*) malloc(flen + 1); 
  size_t status = fread(buffer,1,flen,filep);
  buffer[flen] = '\0';
  fclose(filep);
  return buffer;
}

