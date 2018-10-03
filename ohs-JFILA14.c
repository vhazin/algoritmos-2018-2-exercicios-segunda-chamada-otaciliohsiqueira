#include <stdio.h>
#include <stdlib.h>

// Struct Elementos
typedef struct element{
    struct element *proximo;
    int valor;
} Element;

// Struct Fila
typedef struct fila{
    Element *primeiro;
    Element *ultimo;
} Fila;

// Prototipo de funcao
Fila* criaFila();
void addValue(Fila *fila, int entrada);
void removeValue(Fila *fila, int entrada);
void printValue(Fila *fila);


// Funcao Cria FILA
Fila* criaFila(){
    Fila *fila = malloc(sizeof(fila));
    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

// Funcao Adcionar Elemento na FILA
void addValue(Fila *fila, int entrada){
    Element *atual = (Element *)malloc(sizeof(Element));
    atual->proximo = NULL;
    atual->valor = entrada;

    if (fila->primeiro == NULL){
        fila->primeiro = atual;
        fila->ultimo = atual;
    } else {   
        fila->ultimo->proximo = atual;
        fila->ultimo = atual;
    }

    return;
}

// Funcao Remover Elemento na FILA
void removeValue(Fila *fila, int entrada){
    Element *atual, *anterior;
    atual = fila->primeiro;

    if (atual == NULL){
        return;
    }
    if (atual->valor == entrada){
        fila->primeiro = atual->proximo;
        free(atual);
        return;
    }
    while(atual->valor != entrada){
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = atual->proximo;
    free(atual);
}

// Funcao Printar FILA
void printValue(Fila *fila){
    while (fila->primeiro != NULL){
        printf("%d ", fila->primeiro->valor);
        fila->primeiro = fila->primeiro->proximo;
    }
}

// Funcao Main
int main (void){
    Fila *fila = criaFila();

    int qtdPessoas;
    scanf("%d", &qtdPessoas);
    while (qtdPessoas--){
        int valor;
        scanf("%d", &valor);
        addValue(fila, valor);
    }
    scanf("%d", &qtdPessoas);
    while (qtdPessoas--){
        int valor;
        scanf("%d", &valor);
        removeValue(fila, valor);
    }

    printValue(fila);
    printf("\n");
    return 0;
}