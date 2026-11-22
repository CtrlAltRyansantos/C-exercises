#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estruturas/listaDuplamenteEncadeada.h"
#include "estruturas/abb.h"

#define N 100000
#define K 20000

void preencherVetorRec(NoArvore *no, int *vetor, int *pos) {
    if (no == NULL) {
        return;
    }

    preencherVetorRec(no->filhoEsquerdo, vetor, pos);

    vetor[*pos] = no->key;
    (*pos)++;

    preencherVetorRec(no->filhoDireito, vetor, pos);
}

void preencherVetor(Abb *abb, int *vetor) {
    int pos = 0;

    preencherVetorRec(abb->root, vetor, &pos);
}

int buscaBinaria(int *vetor, int inicio, int fim, int key) {
    int meio;

    if (inicio > fim) {
        return 0;
    }

    meio = inicio + (fim - inicio) / 2;

    if (vetor[meio] == key) {
        return 1;
    } else if (key < vetor[meio]) {
        return buscaBinaria(vetor, inicio, meio - 1, key);
    } else {
        return buscaBinaria(vetor, meio + 1, fim, key);
    }
}

int buscaSequencial(int *vetor, int n, int key) {
    int i;

    for (i = 0; i < n; i++) {
        if (vetor[i] == key) {
            return 1;
        }
    }

    return 0;
}
int main(int argc, char *argv[]) {
    int n = N, k = K, inseridos = 0, key;
    int *vetor, *chaves;
    int i;
    float valor;
    clock_t inicio, fim;
    Abb *abb;
    Lista *lista;

    srand((unsigned int)time(NULL)); /* para os numeros aleatorios */
    abb = criaArvore();
    lista = criaLista();

    if (argc >= 2) {
        n = atoi(argv[1]);
    }
    if (argc >= 3) {
        k = atoi(argv[2]);
    }

    /* sorteia chaves e insere se nao existirem na abb */
    while (inseridos < n) {
        key = rand();
        valor = (float)(rand() % 100000) / 100.0f;

        if (buscarIterativo(abb, key) == NAO_ENCONTRADO) {
            inserirIterativo(abb, key, valor);
            inserirFim(lista, key, valor);
            inseridos++;
        }
    }

    /* preenche o vetor percorrendo a abb em ordem */
    vetor = (int *) malloc(n * sizeof(int));
    preencherVetor(abb, vetor);

    /* gera K chaves de busca */
    chaves = (int *) malloc(k * sizeof(int));

    for (i = 0; i < k; i++) {
        if (i % 2 == 0) {
            chaves[i] = vetor[rand() % n];
        } else {
            chaves[i] = rand();
        }
    }

    /* busca na ABB */
    inicio = clock();
    for (i = 0; i < k; i++) {
        buscarIterativo(abb, chaves[i]);
    }
    fim = clock();
    printf("Busca em ABB: %.3f s\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    /* busca binaria no vetor */
    inicio = clock();
    for (i = 0; i < k; i++) {
        buscaBinaria(vetor, 0, n - 1, chaves[i]);
    }
    fim = clock();
    printf("Busca binaria no vetor: %.3f s\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    /* busca sequencial no vetor */
    inicio = clock();
    for (i = 0; i < k; i++) {
        buscaSequencial(vetor, n, chaves[i]);
    }
    fim = clock();
    printf("Busca sequencial no vetor: %.3f s\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    /* busca sequencial na lista */
    inicio = clock();
    for (i = 0; i < k; i++) {
        buscarElemento(lista, chaves[i]);
    }
    fim = clock();
    printf("Busca sequencial na lista: %.3f s\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    free(chaves);
    free(vetor);
    liberaArvore(abb);
    liberarLista(lista);

    return 0;
}