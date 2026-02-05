#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char opt_newline[] = "-n";
static const char opt_enable_escapes[] = "-e";
static const char opt_disable_escapes[] = "-E";
static const char opt_version[] = "--version";

int disable_newline = 0;
int enable_escapes = 0;

int possuiOpt(char* parametro){
    if(strcmp(parametro, opt_newline) == 0){
        disable_newline = 1;
        return 1;
    }else if(strcmp(parametro, opt_enable_escapes) == 0){
        enable_escapes = 1;
        return 1;
    }
    else if(strcmp(parametro, opt_disable_escapes) == 0){
        enable_escapes = 0;
        return 1;
    } else if(strcmp(parametro, opt_version) == 0){
        enable_escapes = 1;
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("\n");
        exit(0);
    }
    for(int i=1; i < argc; i++){
        if(possuiOpt(argv[i])){
            continue;
        }else{
        
          for(int j=i; j < argc; j++){
            printf("%s", argv[j]);
            if(j+1<argc){
                printf(" ");
            }

          }
          if(!disable_newline){
            printf("\n");
          }
          break;  
        }
    }

}