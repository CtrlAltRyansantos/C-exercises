#include "listaDuplamenteEncadeada.h"
#include <stdlib.h>
#include <stdio.h>


No* criarNo(int key, float valor) {
    No *no = malloc(sizeof(No));
    if (no == NULL){
         return NULL;
    }

    no->key = key;
    no->valor = valor;
    no->proximo = NULL;
    no->anterior = NULL;
    return no;
}

Lista* criaLista(void) {
    Lista *lista = malloc(sizeof(Lista));
    if (lista == NULL){
        return NULL;
    }
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

void inserirInicio(Lista *lista, int key, float valor) {
    No *novo = criarNo(key, valor);
    if (novo == NULL){
        NULL;
    }

    if (lista->head == NULL) {
        lista->head = novo;
        lista->tail = novo;
    } else {
        novo->proximo = lista->head;
        lista->head->anterior = novo;
        lista->head = novo;
    }
}

void inserirFim(Lista *lista, int key, float valor) {
    No *novo = criarNo(key, valor);
    if (novo == NULL){
        return;
      }

    if (lista->tail == NULL) {
        lista->head = novo;
        lista->tail = novo;
    } else {
        novo->anterior = lista->tail;
        lista->tail->proximo = novo;
        lista->tail = novo;
    }
}

void remover(Lista *lista, int key) {
    No *atual = lista->head;

    while (atual != NULL && atual->key != key) {
        atual = atual->proximo;
    }
    if (atual == NULL){
        return;
    }

    if (atual->anterior != NULL){
        atual->anterior->proximo = atual->proximo;
    }
    else{
        lista->head = atual->proximo;
    }

    if (atual->proximo != NULL){
        atual->proximo->anterior = atual->anterior;
    }
    else{
        lista->tail = atual->anterior;
    }

    free(atual);
}

int lenLista(Lista *lista) {
    int n = 0;
    No *atual;
    atual = lista->head;

    while (atual != NULL) {
        n++;
        atual = atual->proximo;
    }

    return n;
}

void ordenar(Lista *lista) {
    int n, i = 0, j = 0;
    n = lenLista(lista);
    if (n < 2){ 
        return;
    }

    No **vetor = malloc(n * sizeof(No *));
    if (vetor == NULL) return;

    No *atual = lista->head;
    for (i = 0; i < n; i++) {
        vetor[i] = atual;
        atual = atual->proximo;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (vetor[j]->key > vetor[j+1]->key) {
                No *temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j + 1] = temp;
            }
        }
    }

    lista->head = vetor[0];
    lista->tail = vetor[n-1];

   for (i = 0; i < n; i++) {
        if (i == 0) {
        vetor[i]->anterior = NULL;
                } 
        else {
        vetor[i]->anterior = vetor[i - 1];
                }

        if (i == n - 1) {
        vetor[i]->proximo = NULL;
                } 
        else {
        vetor[i]->proximo = vetor[i + 1];
                }
        }
}


void printarLista(Lista *lista) {
    if (lista->head == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    for (No *atual = lista->head; atual != NULL; atual = atual->proximo) {
        printf("\n no de key: %d\n", atual->key);
        printf("valor: %f\n", atual->valor);
    }
}

void liberarLista(Lista *lista) {
    No *atual;
    atual = lista->head;
    while (atual != NULL) {
        No *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(lista);
}

float buscarElemento(Lista *lista, int key){
    No *atual, *prox;
    atual = lista->head;

    while (atual != NULL) {
        if(atual->key == key){
            return atual->valor;
        }
        prox = atual->proximo;
        atual = prox;
    }
    return NAO_ENCONTRADO;

}