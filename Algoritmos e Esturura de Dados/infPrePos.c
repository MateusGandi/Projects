#include <stdio.h>
#include <stdlib.h>
typedef struct NoArv {
    char valor;
    struct NoArv *NoDireito;
    struct NoArv *NoEsquerdo;
}NoArv;

NoArv * criarNovoNo(char val)
{
    NoArv *NovoNO = (NoArv*)malloc(sizeof(NoArv));
    NovoNO->valor = val;
    NovoNO->NoDireito = NULL;
    NovoNO->NoEsquerdo = NULL; 
    return NovoNO; 
}

void analisar(NoArv *Raiz, char *Pre, char *Inf, int index,int tam)
{
    int j, index1 = 0, index2 = 0;
    for(j=0;j<tam;j++){
        if(Inf[j]==Raiz->valor){
            index1 = j;
        }
        if(Inf[j]==Pre[index]){
            index2 = j;
        }
    }
        
    if(index1>index2){
        if(Raiz->NoEsquerdo==NULL){
            Raiz->NoEsquerdo = criarNovoNo(Pre[index]);
        }else{
            analisar(Raiz->NoEsquerdo,Pre,Inf,index,tam);
        }
    }else{
        if(Raiz->NoDireito==NULL){
            Raiz->NoDireito = criarNovoNo(Pre[index]);
        }else{
            analisar(Raiz->NoDireito,Pre,Inf,index,tam);
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
        printf("%c",Raiz->valor);
    }
}
int main()
{
    int casos, tam, i,j;
    NoArv *Raiz = NULL;
    do{
        scanf("%d",&casos);
    }while(casos>2000);
    for(j=0;j<casos;j++){
        do{
            scanf("%d",&tam);
        }while(tam<0||tam>52);
        
        char Prefixa[tam];
        char Infixa[tam];
        
        scanf("%s %s",Prefixa,Infixa);
        
        Raiz = criarNovoNo(Prefixa[0]);
        for(i=1;i<tam;i++){
            analisar(Raiz,Prefixa,Infixa,i,tam);
        }
        percorerArvPos(Raiz);
        printf("\n");
    }
    
    return 0;
}