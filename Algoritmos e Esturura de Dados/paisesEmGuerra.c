#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int destino;
    int tempo;
    struct Node* proximo;
} Node;

typedef struct Vertice {
    Node* listaAdj;
} Vertice;

bool temLigacaoBidirecional(Vertice* grafo, int vertice1, int vertice2) {
    Node* atual = grafo[vertice1].listaAdj;
    while (atual != NULL) {
        if (atual->destino == vertice2) {
            return true;
        }
        atual = atual->proximo;
    }

    atual = grafo[vertice2].listaAdj;
    while (atual != NULL) {
        if (atual->destino == vertice1) {
            return true;
        }
        atual = atual->proximo;
    }

    return false;
}

void adicionarAresta(Vertice* grafo, int verticeX, int verticeY, int tempo) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->destino = verticeY;
    novoNo->tempo = tempo;
    novoNo->proximo = grafo[verticeX].listaAdj;
    grafo[verticeX].listaAdj = novoNo;

    novoNo = (Node*)malloc(sizeof(Node));
    novoNo->destino = verticeX;
    novoNo->tempo = tempo;
    novoNo->proximo = grafo[verticeY].listaAdj;
    grafo[verticeY].listaAdj = novoNo;
}

int encontrarTempoMinimo(Vertice* grafo, int origem, int destino, bool* visitado) {
    if (origem == destino) {
        return 0;
    }

    visitado[origem] = true;

    int tempoMinimo = INT_MAX;
    Node* atual = grafo[origem].listaAdj;
    while (atual != NULL) {
        int proximoDestino = atual->destino;
        if (!visitado[proximoDestino]) {
            int tempoSubCaminho = encontrarTempoMinimo(grafo, proximoDestino, destino, visitado);
            if (tempoSubCaminho >= 0) {
                int tempoTotal = tempoSubCaminho + atual->tempo;
                if (tempoTotal < tempoMinimo) {
                    tempoMinimo = tempoTotal;
                }
            }
        }
        atual = atual->proximo;
    }

    visitado[origem] = false;

    if (tempoMinimo == INT_MAX) {
        return -1;
    } else {
        return tempoMinimo;
    }
}

int main() {
    int N, E;
    while (true) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) {
            break; 
        }

        Vertice* grafo = (Vertice*)malloc((N + 1) * sizeof(Vertice));
        for (int i = 1; i <= N; i++) {
            grafo[i].listaAdj = NULL;
        }

        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            adicionarAresta(grafo, X, Y, H);
        }

        int K;
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            int O, D;
            scanf("%d %d", &O, &D);

            if (temLigacaoBidirecional(grafo, O, D)) {
                printf("0\n");
            } else {
                bool* visitado = (bool*)malloc((N + 1) * sizeof(bool));
                for (int j = 1; j <= N; j++) {
                    visitado[j] = false;
                }
                int tempoMinimo = encontrarTempoMinimo(grafo, O, D, visitado);
                free(visitado);

                if (tempoMinimo == -1) {
                    printf("Nao e possivel entregar a carta\n");
                } else {
                    printf("%d\n", tempoMinimo);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            Node* atual = grafo[i].listaAdj;
            while (atual != NULL) {
                Node* proximo = atual->proximo;
                free(atual);
                atual = proximo;
            }
        }
        free(grafo);
    }

    return 0;
}
