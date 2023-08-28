#include <stdio.h>
#include <stdlib.h>
typedef struct NoArv {
    int valor;
    struct NoArv *NoDireito;
    struct NoArv *NoEsquerdo;
}NoArv;

NoArv * criarNovoNo(int val)
{
    NoArv *NovoNO = (NoArv*)malloc(sizeof(NoArv));
    NovoNO->valor = val;
    NovoNO->NoDireito = NULL;
    NovoNO->NoEsquerdo = NULL; 
    return NovoNO; 
}

void analisar(NoArv *Raiz, int valor)
{
    if(Raiz->valor > valor){
        if(Raiz->NoEsquerdo!=NULL){
            analisar(Raiz->NoEsquerdo,valor);
        }else{
            Raiz->NoEsquerdo = criarNovoNo(valor);
        }
    }else{
        if(Raiz->NoDireito!=NULL){
            analisar(Raiz->NoDireito,valor);
        }else{
            Raiz->NoDireito = criarNovoNo(valor);
        }
    }
}

void percorerArvPre(NoArv *Raiz){
    if(Raiz!=NULL){
        printf(" %d",Raiz->valor);
        if(Raiz->NoEsquerdo!=NULL){
            percorerArvPre(Raiz->NoEsquerdo);
        }
        if(Raiz->NoDireito!=NULL){
            percorerArvPre(Raiz->NoDireito);
        }
    }
}

void percorerArvInf(NoArv *Raiz){
    if(Raiz!=NULL){
        if(Raiz->NoEsquerdo!=NULL){
            percorerArvInf(Raiz->NoEsquerdo);
        }
        printf(" %d",Raiz->valor);
        if(Raiz->NoDireito!=NULL){
            percorerArvInf(Raiz->NoDireito);
        }
    }
}

void percorerArvPos(NoArv *Raiz){
    if(Raiz!=NULL){
        if(Raiz->NoEsquerdo!=NULL){
            percorerArvPos(Raiz->NoEsquerdo);
        }
        if(Raiz->NoDireito!=NULL){
            percorerArvPos(Raiz->NoDireito);
        }
        printf(" %d",Raiz->valor);
    }
}


int main()
{
    int casos, tam,i,j;
    do{
        scanf("%d",&casos);
    }while(casos>1000||casos<1);
    for(j=1;j<=casos;j++){
        NoArv *RAIZ = NULL;
        do{
        scanf("%d",&tam);
        }while(tam<1||tam>500);
        
        int vetor[tam];
        
        for(i=0;i<tam;i++){
            scanf("%d",&vetor[i]);
            if(RAIZ==NULL){
                RAIZ = criarNovoNo(vetor[0]);
            }else{
                analisar(RAIZ,vetor[i]);
            }
        }
    printf("Case %d:",j);
    printf("\nPre.:");
    percorerArvPre(RAIZ);
    printf("\nIn..:");
    percorerArvInf(RAIZ);
    printf("\nPost:");
    percorerArvPos(RAIZ);
    printf("\n\n");
    }
    return 0;
}