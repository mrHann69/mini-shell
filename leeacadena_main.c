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

  while(1) {
          printf("> ");
          leer_de_teclado(BUFSIZ,comando);
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
  }

  return 0;
}

