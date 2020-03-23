#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "desplazar.h"

#define MAGIC ((char)0xa6)
#define OVH 50

// Este es el string base.  No debe ser modificado.
char *ro= "los 4 puntos cardinales son 3: el norte y el sur";
//                   11111111112222222222333333333344444444
//         012345678901234567890123456789012345678901234567
// len: largo de ro
// size: tamaño de mem
int len, size;
// rw: El string que debe ser modificado por desplazar.
// mem: Un espacio grande que incluye el espacio de rw.
// La idea es que solo se debe alterar rw, no lo que rodea a rw (que es mem).
char *mem, *rw;

// verify: chequea que str y res sean iguales.  De lo contrario diagnostica
// un resultado incorrecto.
void verify(char *str, char *res) {
  fprintf(stderr, "resultado correcto  : %s\n", res);
  if (strcmp(str, res)!=0) {
    fprintf(stderr, "resultado incorrecto: %s\n", str);
    fprintf(stderr, "Lo siento, su tarea no aprueba este test\n");
    exit(1);
  }
}

// check: verifica que no se haya modificado mas alla de los limites
// de un string.  De lo contrario diagnostica un error.
// mem[0] ... mem[OVH-1], mem[OVH+len+1], ..., mem[size-1] deben
// ser siempre MAGIC
// No deben ser alterados por desplazar o desplazamiento
void check() {
  for (int i= 0; i<OVH; i++) {
    if (mem[i]!=MAGIC) {
      fprintf(stderr, "caracter %d de mem fue incorrectamente alterado\n", i);
      exit(1);
    }
  }
  for (int i= OVH+len+1; i<size; i++) {
    if (mem[i]!=MAGIC) {
      fprintf(stderr, "caracter %d de mem fue incorrectamente alterado\n", i);
      exit(1);
    }
  }
} 

int main() {
  // Inicializacion
  len= strlen(ro);
  size= len+1+OVH*2;
  mem= malloc(size);
  for (int i= 0; i<size; i++)
    mem[i]= MAGIC; // 0b10100110
  rw= mem+50;
  //printf("%d\n", rw);

  // Los 8 tests
  // ----------------------------------------
  printf("1er. test: desplazar \"4 puntos \" en 3 posiciones sin desborde\n");
  strcpy(rw, ro);
  desplazar(rw, 4, 9, 3);
  verify(rw, "los 4 p4 puntos dinales son 3: el norte y el sur");
  check();

  // ----------------------------------------
  printf("2do. test: desplazar \"el norte \" en -20 posiciones sin desborde\n");
  strcpy(rw, ro);
  desplazar(rw, 31, 9, -20);
  verify(rw, "los 4 puntoel norte les son 3: el norte y el sur");
  check();

  // ----------------------------------------
  printf("3er. test: desplazar \"norte y\" en 9 posiciones con desborde\n");
  printf("Se pide desplazar 7 caracteres pero solo se pueden desplazar 5\n");
  strcpy(rw, ro);
  desplazar(rw, 34, 7, 9);
  verify(rw, "los 4 puntos cardinales son 3: el norte y enorte");
  check();

  // ----------------------------------------
  printf("4to. test: desplazar \"cardinales\" en -17 posiciones con desborde\n");
  strcpy(rw, ro);
  desplazar(rw, 13, 10, -17);
  verify(rw, "inalespuntos cardinales son 3: el norte y el sur");
  check();

  char *res;

  // ----------------------------------------
  printf("5to. test: desplazamiento de \"4 puntos \" en 3 posiciones sin desborde\n");
  res= desplazamiento(ro, 4, 9, 3);
  verify(res, "los 4 p4 puntos dinales son 3: el norte y el sur");
  free(res);

  // ----------------------------------------
  printf("6to. test: desplazamiento de \"el norte \" en -20 posiciones sin desborde\n");
  res= desplazamiento(ro, 31, 9, -20);
  verify(res, "los 4 puntoel norte les son 3: el norte y el sur");
  free(res);

  // ----------------------------------------
  printf("7mo. test: desplazamiento de \"norte y\" en 9 posiciones con desborde\n");
  printf("Se pide desplazar 7 caracteres pero solo se pueden desplazar 5\n");
  res= desplazamiento(ro, 34, 7, 9);
  verify(res, "los 4 puntos cardinales son 3: el norte y enorte");
  free(res);

  // ----------------------------------------
  printf("8vo. test: desplazamiento de \"cardinales\" en -17 posiciones con desborde\n");
  res= desplazamiento(ro, 13, 10, -17);
  verify(res, "inalespuntos cardinales son 3: el norte y el sur");
  free(res);

  printf("Felicitaciones: su tarea aprobo todos los tests\n");
  return 0;
}
