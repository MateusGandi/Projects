#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
    int numeroVertices;
    int grauMax;
    int **arestas;
    int *listaAdjacencia;
} Labirinto;

Labirinto *criaLabirinto(int numeroDeVertices, int GrauMaximo) {
    Labirinto *lab = (Labirinto *)malloc(sizeof(Labirinto));
    if (lab != NULL) {
        int i;
        lab->numeroVertices = numeroDeVertices;
        lab->grauMax = GrauMaximo;
        lab->listaAdjacencia = (int *)calloc(numeroDeVertices, sizeof(int)); //criar um array de tamanho numVertices com todos os elementos inicializados com zero.
        lab->arestas = (int **)malloc(numeroDeVertices * sizeof(int *));//está alocando memória para o array de ponteiros para arestas do grafo (lista de adjacência)
        for (i = 0; i < numeroDeVertices; i++) {
            lab->arestas[i] = (int *)malloc(GrauMaximo * sizeof(int));
        }
    }
    return lab;
}

void buscaLargura(Labirinto *lab, int inicio, int *visitados) {
    int i, vertice, NV, cont = 0;
    int *fila, IF = 0, FF = 0;
    for (i = 0; i < lab->numeroVertices; i++) {
        visitados[i] = 0;
    }
    NV = lab->numeroVertices;
    fila = (int *)malloc(NV * sizeof(int));
    FF++;
    fila[FF] = inicio;
    visitados[inicio] = 1;
    while (IF != FF) {
        IF = (IF + 1) % NV;
        vertice = fila[IF];
        for (i = 0; i < lab->listaAdjacencia[vertice]; i++) {
            if (!visitados[lab->arestas[vertice][i]]) {
                cont++;
                FF = (FF + 1) % NV;
                fila[FF] = lab->arestas[vertice][i];
                visitados[lab->arestas[vertice][i]] = 1;
            }
        }
    }
    printf("%d\n", cont * 2);
    free(fila);
}

void inserirAresta(Labirinto *lab, int origem, int destino) {
    if (lab != NULL) {
        if (origem >= 0 && origem < lab->numeroVertices && destino >= 0 && destino < lab->numeroVertices) {
            lab->arestas[origem][lab->listaAdjacencia[origem]] = destino;
            lab->listaAdjacencia[origem]++;
            lab->arestas[destino][lab->listaAdjacencia[destino]] = origem;
            lab->listaAdjacencia[destino]++;
        }
    }
}

int main() {
    int numCasosTeste, inicio, numVertices, numArestas, *visitados, i, v1, v2;
    Labirinto *labirintos;

    scanf("%d", &numCasosTeste);

    while (numCasosTeste--) {
        scanf("%d", &inicio);
        scanf("%d %d", &numVertices, &numArestas);

        visitados = calloc(numVertices, sizeof(int));
        labirintos = criaLabirinto(numVertices, numArestas);

        for (i = 0; i < numArestas; i++) {
            scanf("%d %d", &v1, &v2);
            inserirAresta(labirintos, v1, v2);
        }

        buscaLargura(labirintos, inicio, visitados);

        //liberaLabirinto(labirintos);
    }

    return 0;
}