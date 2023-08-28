#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1024
#define MAX_M 1024

int numero_pessoas, numero_emails, N, M, qtd_spam, numero_pessoa_atual = 0;
int lista_amigos[MAX_N][MAX_M];
int visitado[MAX_N];
char nome_pessoa[50], spam1[21], spam2[21], spam3[21], lista_emails[MAX_M][21];
int i, j, y, envio_spam, qtd_amigos[MAX_N], limite_spam1, limite_spam2;

void dfs(int pessoa, int limite_spam);

int main() {
    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }

        for (i = 1; i <= N; ++i) {
            qtd_amigos[i] = 0;
            j = 0;
            while (1) {
                j++;
                scanf("%d", &y);
                if (y == 0) {
                    break;
                }
                qtd_amigos[i]++;
                lista_amigos[i][j] = y;
                visitado[i] = 0;
            }
        }

        for (int spam = 1; spam <= 101; spam++) {
            qtd_spam = spam;
            scanf("%d", &envio_spam);
            if (envio_spam == 0) {
                break;
            }
            scanf("%d", &limite_spam1);
            scanf("%d", &limite_spam2);
            scanf("%s", spam1);
            scanf("%s", spam2);
            scanf("%s", spam3);
            dfs(envio_spam, spam);
            for (i = 1; i <= N; ++i) {
                if (visitado[i] < spam) {
                    int indice = i;
                    visitado[i] += 1;
                    if (visitado[i] > 1) {
                        indice = ((visitado[i] - 1) * N) + i;
                    }
                    strcpy(lista_emails[indice], spam1);
                }
            }
        }

        for (int tm = 1; tm <= N; tm++) {
            scanf("%s", nome_pessoa);
            printf("%s:", nome_pessoa);
            for (i = 1; i <= qtd_spam - 1; i++) {
                numero_emails = tm;
                if (i > 1) {
                    numero_emails = ((i - 1) * N) + tm;
                }
                printf(" %s", lista_emails[numero_emails]);
            }
            printf("\n");
        }
    }

    return 0;
}

void dfs(int pessoa, int limite_spam) {
    visitado[pessoa] = visitado[pessoa] + 1;
    int indice = pessoa;
    if (visitado[pessoa] > 1) {
        indice = ((visitado[pessoa] - 1) * N) + pessoa;
    }

    if (qtd_amigos[pessoa] < limite_spam1) {
        strcpy(lista_emails[indice], spam1);
    }
    if (qtd_amigos[pessoa] < limite_spam2 && qtd_amigos[pessoa] >= limite_spam1) {
        strcpy(lista_emails[indice], spam2);
    }
    if (qtd_amigos[pessoa] >= limite_spam2) {
        strcpy(lista_emails[indice], spam3);
    }

    for (int controle = 1; controle <= qtd_amigos[pessoa]; controle++) {
        int amigo_atual = lista_amigos[pessoa][controle];
        if (qtd_amigos[pessoa] > 0 && visitado[amigo_atual] < limite_spam) {
            dfs(amigo_atual, limite_spam);
        }
    }
}
