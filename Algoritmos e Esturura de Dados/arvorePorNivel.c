#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct NoArv {
    int valor;
    struct NoArv *NoDireito;
    struct NoArv *NoEsquerdo;
    struct NoArv *prox;
}NoArv;

typedef struct{
    NoArv *ult;
} FILA;

NoArv * criarNovoNo(int val)
{
    NoArv *NovoNO = (NoArv*)malloc(sizeof(NoArv));    
    NovoNO->valor = val;
    NovoNO->NoDireito = NULL;
    NovoNO->NoEsquerdo = NULL; 
    NovoNO->prox = NULL; 
    
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

void enfileirar(NoArv *Raiz,NoArv *proximo){
    Raiz->prox = proximo;
}

void percorer(NoArv *Raiz, FILA *fila,_Bool flag){
    if(Raiz!=NULL){
        if(!flag){
            printf("%d",Raiz->valor);
            flag = true;
        }else{
            printf(" %d",Raiz->valor);
        }
        
        
        if(Raiz->NoEsquerdo!=NULL){
            enfileirar(fila->ult,Raiz->NoEsquerdo);
            fila->ult = Raiz->NoEsquerdo;
        }
        
        if(Raiz->NoDireito!=NULL){
            enfileirar(fila->ult,Raiz->NoDireito);
            fila->ult = Raiz->NoDireito;
        }
        percorer(Raiz->prox,fila,flag);
    }
    
}

int main()
{
    int casos, tam,i,j;
    do{
        scanf("%u",&casos);
    }while(casos>1000||casos<1);
    
    for(j=1;j<=casos;j++){
        NoArv *RAIZ = NULL;
        FILA *fila = (FILA*)malloc(tam*sizeof(FILA));
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
        printf("Case %u:\n",j);
        fila->ult = RAIZ;
        _Bool flag = false;
        percorer(fila->ult,fila,flag);
        printf("\n\n");
    }
    return 0;
    
}