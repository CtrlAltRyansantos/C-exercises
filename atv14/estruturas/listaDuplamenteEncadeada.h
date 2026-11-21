#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

typedef struct _no {
    int key;
    float valor;
    struct _no *proximo;
    struct _no *anterior;
} No;

typedef struct {
    No *head;
    No *tail;
} Lista;

#define NAO_ENCONTRADO -99999.99;

Lista* criaLista(void);
No* criarNo(int key, float valor);

void inserirInicio(Lista *lista, int key, float valor);
void inserirFim(Lista *lista, int key, float valor);
void remover(Lista *lista, int key);

void ordenar(Lista *lista);
int lenLista(Lista *lista);
void printarLista(Lista *agenda);
void liberarLista(Lista *lista);

float buscarElemento(Lista *lista, int key);
#endif