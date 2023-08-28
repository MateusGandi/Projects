#include <stdio.h>
#include <string.h>

int posicaoAlfabeto(char item) {
    char alfa[27];
    strcpy(alfa, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for (int ii = 0; ii < 26; ii++) {
        if (alfa[ii] == item) {
            return ii;
        }
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    while (N--) {
        int M, j, i;
        char valor[50];

        scanf("%d", &M);
        getchar();

        int total = 0;

        for (i = 0; i < M; i++) {
            j = 0;
            fgets(valor, 50, stdin);
            valor[strcspn(valor, "\n")] = '\0';

            while (valor[j] != '\0') {
                total += posicaoAlfabeto(valor[j]) + i + j;
                j++;
            }
        }

        printf("%d\n", total);
    }

    return 0;
}