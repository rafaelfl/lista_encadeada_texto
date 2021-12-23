#include <stdio.h>
#include <string.h>
#include "ListaTexto.h"

int main(void) {
  char s1[] = "Algoritmos";
  char s2[] = "Estruturas de Dados";
  char s3[50] = "Matrix Revolutions";
  
  char *result;

  int pos_encontrada;

  ListaTexto *lt = cria_lista();

  adicionar_lista(lt, s2);
  adicionar_lista(lt, s1);
  adicionar_lista(lt, s3);
  adicionar_lista(lt, s2);

  imprimir_lista(lt);

  strcpy(s3, "Matrix Ressurections");

  imprimir_lista(lt);

  result = acessar_lista(lt, 2);
  printf("Posição 2 da lista: %s\n", result);

  result = acessar_lista(lt, 5);
  if (result != NULL) {
    printf("Posição 5 da lista: %s\n", result);
  } else {
    printf("A posição 5 não existe na lista!\n");
  }

  // pos_encontrada = buscar_lista(lt, "Matrix ressurections");
  // printf("Posição encontrada: %d\n", pos_encontrada);

  // pos_encontrada = buscar_lista(lt, "Carro");
  // printf("Posição encontrada: %d\n", pos_encontrada);

  // remover_lista(lt, 0);
  // imprimir_lista(lt);

  // remover_lista(lt, 2);
  // imprimir_lista(lt);

  // remover_lista(lt, 5);
  // imprimir_lista(lt);

  destroi_lista(lt);
  
  return 0;
}