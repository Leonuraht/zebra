#include "lexer.h"
#include "vector.h"
#include "fileop.h"


#include <stdbool.h>
#include <string.h>


int main(int argc,char* argv[]){
  if(argc < 2) {
    printf("NO INPUT ARGUMENT PROVIDED. TERMINATING.\n");
  }else{
    
    char flags[argc];size_t flag_pointer = 0;
    char* filename = argv[1];
    
    //Get Flags
    for(int i = 2;i < argc;i++){
      if(argv[i][0] == '-'){
        flags[flag_pointer++] = argv[i][1];
        if(argv[i][2] != '\0'){
          printf("INVALID FLAGS PROVIDED. TERMINATING.\n");
          return 0;
        }
      }else{
        printf("INVALID ARGUMENTS PROVIDED. TERMINATING.\n");
        return 0;
      }
    }

    //check flags
    bool turnbp = false;
    char dummy[flag_pointer];size_t dummy_po = 0;
    for(size_t i = 0;i < flag_pointer;i++){
      for(size_t j = 0;j < dummy_po;j++){
        if(dummy[j] == flags[i]){
          turnbp = true;
          break;
        }
      }
      if(!turnbp){
        dummy[dummy_po++] = flags[i];
      }else{
        turnbp = false;
      }
    }
    dummy[dummy_po] = '\0';

    memcpy(flags,dummy,dummy_po+1);
    char* buffer = openfile(filename);

    printf("FILE : %s \t FLAGS : %s\n",filename,flags);
    printf("\n\n\t\t\tCONTENTS\t\t\t \n %s\n",buffer);
  }
  return 0;
}


