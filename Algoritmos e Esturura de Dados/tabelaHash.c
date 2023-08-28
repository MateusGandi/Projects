#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista {
    int key;
    struct NoLista* prox;
} NoLista;
//no vetor, cada item do vetor possui um lista encadeada
//para tratar as colisões, a key é inserida da lista

NoLista* criarNovoNo(int key) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    novo->key = key;
    novo->prox = NULL;
    return novo;
}

void inserir(NoLista** tabela, int M, int key) {
    int index = key % M;//mod
    NoLista* novo = criarNovoNo(key);

    if (tabela[index] == NULL) {
        tabela[index] = novo;
    } else {
        NoLista* aux = tabela[index];
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void printarTabela(NoLista** tabela, int M) {
    for (int i = 0; i < M; i++) {
        printf("%d -> ", i);
        NoLista* aux = tabela[i];
        
        while (aux != NULL) {
            printf("%d -> ", aux->key);
            aux = aux->prox;
        }
        
        printf("\\ ");
        printf("\n");
    }
}


int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        NoLista** tabela = (NoLista**)malloc(M * sizeof(NoLista*));
        
        for (int i = 0; i < M; i++) {
            tabela[i] = NULL;
        }

        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            inserir(tabela, M, key);
        }

        printarTabela(tabela, M);
        printf("\n");
    }

    return 0;
}
