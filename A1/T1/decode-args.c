#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc!=10) {
    fprintf(stderr, "uso: %s <iteraciones> <fila0> <fila1> ... <fila7>\n",
            argv[0]);
    exit(1);
  }
  //printf("Resultado de la suma: %s\n",argv);
  
  int k= atoi(argv[1]);

  unsigned long long x= 0;
  for (int i= 0; i<8; i++) {
    char *fila= argv[i+2];
    for (int j= 0; j<8; j++)
      x = ( x<<1 ) + fila[j]-'0';
  }
  printf("transiciones= %d, matriz inicial= %8llx (en hexadecimal)\n", k, x);  
  return 0;
}
