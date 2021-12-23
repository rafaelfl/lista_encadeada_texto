
#include <stdio.h>
#include <stdlib.h>
#include "ListaTexto.h"

ListaTexto * cria_lista() {
  ListaTexto *lt = malloc(sizeof(ListaTexto));

  if (lt == NULL) {
    return NULL;
  }

  lt->quantidade = 0;
  lt->primeiro = NULL;

  return lt;
}

void destroi_lista(ListaTexto *l) {
  // primeiro destroi os elementos da lista
  No *atual, *prox;

  atual = l->primeiro; // comece pelo começo!

  // enquanto eu não apagar todos os nós da lista
  while (atual != NULL) {
    // guarda o end do prox pra não perder quando eu der o free()!
    prox = atual->prox;

    // destroi o nó atual da lista
    free(atual);

    // passa para o próximo
    atual = prox;
  }

  free(l);
}

// adiciona ao final da lista
int adicionar_lista(ListaTexto *l, char *texto) {
  // criar o nó a ser adicionado ao final da lista
  No *novo_no = malloc(sizeof(No));

  // não tem mais memória
  if (novo_no == NULL) {
    return -1;
  }

  novo_no->prox = NULL;
  novo_no->texto = texto;

  // se a lista está vazia...
  if (l->primeiro == NULL) {
    // o primeiro elemento passa a ser o próprio nó
    l->primeiro = novo_no;
  // se existirem elementos na lista...
  } else {
    // preciso descobrir qual o último nó da lista...
    No *atual;

    // vamos "passear" pela lista a partir do primeiro nó
    atual = l->primeiro;

    // enquanto eu não estiver no último nó da lista....
    while (atual->prox != NULL) {
      // "navegue" para o próximo nó da lista
      atual = atual->prox;
    }

    // nessa parte do código, o "atual" é o último nó da lista!
    // basta inserir o novo nó depois dele
    atual->prox = novo_no;
  }

  l->quantidade++;
  return 0;
}

// insere em alguma posição da lista
int inserir_lista(ListaTexto *l, int posicao, char *texto) {
  return -1;
}

// retornar o elemento na posição 'posicao'
char * acessar_lista(ListaTexto *l, int posicao) {
  int p = 0;
  No *atual;

  // se a posição indicada não existir
  if (posicao < 0 || posicao >= l->quantidade) {
    return NULL;
  }

  // começa a busca pelo primeiro elemento da lista
  atual = l->primeiro;

  // enquanto eu não chegar na posição "posicao"
  while (p < posicao) {
    // "navega" para o próximo elemento da lista
    atual = atual->prox;

    // incrementa a posição atual da lista
    p++;
  }

  return atual->texto;
}

// retornar o índice do texto buscado ou -1 caso não encontre
int buscar_lista(ListaTexto *l, char *buscado) {
  return -1;
}

// remove um elemento da lista e retorna ele ou NULL caso a posição não exista na lista
char * remover_lista(ListaTexto *l, int posicao) {
  return NULL;
}

// imprime a lista para que possamos verificar o seu estado atual
void imprimir_lista(ListaTexto *l) {
  No *atual;

  atual = l->primeiro;

  printf("[");
  
  while(atual != NULL) {
    printf(" (%s) ", atual->texto);
    atual = atual->prox;
  }
  
  printf("]\n");
}