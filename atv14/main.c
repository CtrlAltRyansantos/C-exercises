#include <stdio.h>
#include "estruturas/listaDuplamenteEncadeada.h"

int main(void) {
    Lista *lista;
    lista = criaLista();

    inserirFim(lista, 2, 4.6);
    inserirInicio(lista, 9, 4.7);
    inserirFim(lista, 4, 7.8);

    ordenar(lista);
    printarLista(lista);

    remover(lista, 102);

    liberarLista(lista);
    return 0;
}