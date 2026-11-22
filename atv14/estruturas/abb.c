
#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
 
Abb* criaArvore(){
    Abb *arvore = (Abb *) malloc(sizeof(Abb));
    if(arvore != NULL){
        arvore->root = NULL;
        arvore->menorElemento = NULL;
    }
    return arvore;
}
 
NoArvore* criaNo(float valor, int key, NoArvore *filhoEsquerdo, NoArvore *filhoDireito){
    NoArvore *no = (NoArvore *) malloc(sizeof(NoArvore));
    if(no == NULL){
        return NULL;
    }
    no->valor = valor;
    no->key = key;
    no->filhoEsquerdo = filhoEsquerdo;
    no->filhoDireito = filhoDireito;
    return no;
}
 
int temFilhos(NoArvore *no){
    if(no->filhoDireito != NULL || no->filhoEsquerdo != NULL){
        return 1;
    }
    return 0;
}
 
int inserirIterativo(Abb *abb, int key, float valor){
    NoArvore *atual = abb->root;
    NoArvore *pai = NULL;
    NoArvore *no;

    while(atual != NULL){
        if(key == atual->key){
            return 0;
        }
        pai = atual;
        if(key < atual->key){
            atual = atual->filhoEsquerdo;
        }
        else{
            atual = atual->filhoDireito;
        }
    }

    no = criaNo(valor, key, NULL, NULL);
    if(no == NULL){
        return 0;
    }

    if(pai == NULL){
        abb->root = no;
    }
    else if(key < pai->key){
        pai->filhoEsquerdo = no;
    }
    else{
        pai->filhoDireito = no;
    }

    if(abb->menorElemento == NULL || key < abb->menorElemento->key){
        abb->menorElemento = no;
    }
    return 1;
}
 
static int inserirNo(NoArvore **p, int key, float valor, NoArvore **criado){
    if(*p == NULL){
        *p = criaNo(valor, key, NULL, NULL);
        *criado = *p;
        return *p != NULL;
    }
    if(key == (*p)->key){
        return 0;
    }
    if(key < (*p)->key){
        return inserirNo(&(*p)->filhoEsquerdo, key, valor, criado);
    }
    return inserirNo(&(*p)->filhoDireito, key, valor, criado);
}
 
int inserirRecursivo(Abb *abb, int key, float valor){
    NoArvore *criado = NULL;
 
    if(!inserirNo(&abb->root, key, valor, &criado)){
        return 0;
    }
    if(abb->menorElemento == NULL || key < abb->menorElemento->key){
        abb->menorElemento = criado;
    }
    return 1;
}
 
float buscarIterativo(Abb *abb, int key){
    NoArvore *atual = abb->root;
 
    while(atual != NULL){
        if(key == atual->key){
            return atual->valor;
        }
        if(key < atual->key){
            atual = atual->filhoEsquerdo;
        }
        else{
            atual = atual->filhoDireito;
        }
    }
    /* printf("Erro: chave %d nao encontrada\n", key); */
    return NAO_ENCONTRADO;
}
 
static float buscarNo(NoArvore *no, int key){
    if(no == NULL){
        printf("Erro: chave %d nao encontrada\n", key);
        return NAO_ENCONTRADO;
    }
    if(key == no->key){
        return no->valor;
    }
    if(key < no->key){
        return buscarNo(no->filhoEsquerdo, key);
    }
    return buscarNo(no->filhoDireito, key);
}
 
float buscarRecursivo(Abb *abb, int key){
    return buscarNo(abb->root, key);
}
 
static void emOrdem(NoArvore *no){
    if(no == NULL){
        return;
    }
    emOrdem(no->filhoEsquerdo);
    printf("%d: %.2f\n", no->key, no->valor);
    emOrdem(no->filhoDireito);
}
 
void listarElementos(Abb *abb){
    emOrdem(abb->root);
}
 
static void liberaNos(NoArvore *no){
    if(no == NULL){
        return;
    }
    liberaNos(no->filhoEsquerdo);
    liberaNos(no->filhoDireito);
    free(no);
}
 
void liberaArvore(Abb *abb){
    liberaNos(abb->root);
    free(abb);
}
 