#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char **vector;
  int i;
  pid_t pid;
  char salir[5] = {'e','x','i','t','\0'};
  while(1) {
        printf("> ");
		leer_de_teclado(BUFSIZ,comando);
		if(strcmp(comando,salir)!=0){
          	pid = fork();
          	if (pid < 0) {
                  printf("No pude crear un proceso\n");
                  return 2;
          	} else if (pid == 0) {
                vector = de_cadena_a_vector(comando);
                execvp(vector[0],vector);
          	} else {
                  wait(NULL);
          	}
        }else{
			return 0;
        }
  }

  return 0;
}

