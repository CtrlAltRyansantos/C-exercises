#ifndef ABB_H
#define ABB_H
 
#define NAO_ENCONTRADO -99999.99f
 
typedef struct _noArvore{
    float valor;
    int key;
    struct _noArvore *filhoEsquerdo;
    struct _noArvore *filhoDireito;
} NoArvore;
 
typedef struct{
    NoArvore *root;
    NoArvore *menorElemento;
} Abb;
 
void listarElementos(Abb *abb);
float buscarIterativo(Abb *abb, int key);
float buscarRecursivo(Abb *abb, int key);
int inserirIterativo(Abb *abb, int key, float valor);
int inserirRecursivo(Abb *abb, int key, float valor);
 
Abb* criaArvore();
NoArvore* criaNo(float valor, int key, NoArvore *filhoEsquerdo, NoArvore *filhoDireito);
int temFilhos(NoArvore *no);
void liberaArvore(Abb *abb);
 
#endif
 