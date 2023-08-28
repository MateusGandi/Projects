#include <stdio.h>

int pai[100001];
int altura[100001];

void inicializarConjunto(int numBancos) {
    for (int i = 1; i <= numBancos; i++) {
        pai[i] = i;
        altura[i] = 0;
    }
}

int encontrarRaiz(int banco) {
    int raiz = banco;
    while (raiz != pai[raiz]) {
        raiz = pai[raiz];
    }
    return raiz;
}

void unirConjuntos(int banco1, int banco2) {
    int raizBanco1 = encontrarRaiz(banco1);
    int raizBanco2 = encontrarRaiz(banco2);

    if (raizBanco1 == raizBanco2) {
        return;
    }

    if (altura[raizBanco1] < altura[raizBanco2]) {
        pai[raizBanco1] = raizBanco2;
    } else if (altura[raizBanco1] > altura[raizBanco2]) {
        pai[raizBanco2] = raizBanco1;
    } else {
        pai[raizBanco2] = raizBanco1;
        altura[raizBanco1]++;
    }
}

int main() {
    int numBancos, numOperacoes;
    scanf("%d %d", &numBancos, &numOperacoes);

    inicializarConjunto(numBancos);

    char operacao;
    int banco1, banco2;

    for (int i = 0; i < numOperacoes; i++) {
        scanf(" %c %d %d", &operacao, &banco1, &banco2);
        if (operacao == 'F') {
            unirConjuntos(banco1, banco2);
        } else if (operacao == 'C') {
            if (encontrarRaiz(banco1) == encontrarRaiz(banco2)) {
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
    }

    return 0;
}
