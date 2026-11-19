#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAXK 100
#define MAXN 100000

/* O programa recebe K e N por argumentos na hora de rodar o executavel */

void geradorRandom(int *v, int n);
void bubbleSort(int *v, int n);
void insertionSort(int *v, int n);
void selectionSort(int *v, int n);
void combSort(int *v, int n);
double calcularTempo(struct timeval inicio, struct timeval fim);

int main(int argc, char *argv[]) {
    int k, n, i, j;
    static int v[MAXK][MAXN];
    int aux[MAXN];

    struct timeval inicio, fim;
    double tempoBubble, tempoInsertion, tempoSelection, tempoComb;

    srand((unsigned int)time(NULL));

    if (argc != 3) {
        printf("Uso: %s <k> <n>\n", argv[0]);
        printf("k = quantidade de vetores (maximo %d)\n", MAXK);
        printf("n = posicoes por vetor (maximo %d)\n", MAXN);
        return 1;
    }

    k = atoi(argv[1]);
    n = atoi(argv[2]);

    if (k <= 0 || k > MAXK || n <= 0 || n > MAXN) {
        printf("Erro: k deve estar entre 1 e %d e n entre 1 e %d.\n", MAXK, MAXN);
        return 1;
    }

    for (i = 0; i < k; i++) {
        geradorRandom(v[i], n);
    }


    printf("Bubble sort: \n");

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            aux[j] = v[i][j];
        }

        gettimeofday(&inicio, NULL);
        bubbleSort(aux, n);
        gettimeofday(&fim, NULL);

        tempoBubble += calcularTempo(inicio, fim);
    }

    printf("Tempo total: %.6f segundos\n", tempoBubble);

    printf("Insertion sort: \n");

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            aux[j] = v[i][j];
        }

        gettimeofday(&inicio, NULL);
        insertionSort(aux, n);
        gettimeofday(&fim, NULL);

        tempoInsertion += calcularTempo(inicio, fim);
    }

    printf("Tempo total: %.6f segundos\n", tempoInsertion);

    printf("Selection sort \n");

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            aux[j] = v[i][j];
        }

        gettimeofday(&inicio, NULL);
        selectionSort(aux, n);
        gettimeofday(&fim, NULL);

        tempoSelection += calcularTempo(inicio, fim);
    }

    printf("Tempo total: %.6f segundos \n", tempoSelection);

    printf("Comb sort\n");

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            aux[j] = v[i][j];
        }

        gettimeofday(&inicio, NULL);
        combSort(aux, n);
        gettimeofday(&fim, NULL);

        tempoComb += calcularTempo(inicio, fim);
    }

    printf("Tempo total: %.6f segundos\n", tempoComb);


    printf("Bubble Sort:    %.6f segundos\n", tempoBubble);
    printf("Insertion Sort: %.6f segundos\n", tempoInsertion);
    printf("Selection Sort: %.6f segundos\n", tempoSelection);
    printf("Comb Sort:      %.6f segundos\n", tempoComb);

    return 0;
}

void geradorRandom(int *v, int n) {
    int i;

    for (i = 0; i < n; i++) {
        v[i] = rand() % 100001;
    }
}

void bubbleSort(int *v, int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *v, int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

void selectionSort(int *v, int n) {
    int i, j, menor, temp;

    for (i = 0; i < n - 1; i++) {
        menor = i;

        for (j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}

void combSort(int *v, int n) {
    int gap, trocou, i, temp;

    gap = n;
    trocou = 1;

    while (gap > 1 || trocou) {
        gap = (gap * 10) / 13;

        if (gap < 1) {
            gap = 1;
        }

        trocou = 0;

        for (i = 0; i + gap < n; i++) {
            if (v[i] > v[i + gap]) {
                temp = v[i];
                v[i] = v[i + gap];
                v[i + gap] = temp;

                trocou = 1;
            }
        }
    }
}

double calcularTempo(struct timeval inicio, struct timeval fim) {
    return (double)(fim.tv_sec - inicio.tv_sec) +
           (double)(fim.tv_usec - inicio.tv_usec) / 1000000.0;
}