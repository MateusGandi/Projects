#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int elem; 
}Array;

typedef struct{
    Array *data;
    int queue, tam;
    int maior, i;
}DS_Queue;

typedef struct{
    Array *data;
    int stack, tam;
    int i;
}DS_Stack;

typedef struct{
    Array *data;
    int priority, tam;
    int maior, i;
}DS_Priority;

typedef struct{
    DS_Queue *Queue;
    DS_Stack *Stack;
    DS_Priority *Priority;
    int impossible;
    int maior, i;
}DS;

void create(DS **d, int tam){
    (*d) = calloc(1, sizeof(DS));
    (*d)->Queue = calloc(1, sizeof(DS_Queue));
    (*d)->Stack = calloc(1, sizeof(DS_Stack));
    (*d)->Priority = calloc(1, sizeof(DS_Priority));
    (*d)->Queue->data = calloc(tam, sizeof(int));
    (*d)->Stack->data = calloc(tam, sizeof(int)); 
    (*d)->Priority->data = calloc(tam, sizeof(int));
    (*d)->Queue->tam = (*d)->Stack->tam = (*d)->Priority->tam = 1;
    (*d)->Queue->i = (*d)->Stack->i = (*d)->Priority->i = 1;
    (*d)->impossible = 0;
    (*d)->maior = -9999;
}


void insertData(DS **d, int val){
    (*d)->Queue->data[(*d)->Queue->tam++].elem = val;
    (*d)->Stack->data[(*d)->Stack->tam++].elem = val;
    (*d)->Priority->data[(*d)->Priority->tam++].elem = val;

}

void comparacao(DS **d, int val){
    int i, j, cont = 0;

    for (i = 1; i < (*d)->Queue->tam; i++)
    {
        if(val!=(*d)->Queue->data[i].elem){
            cont++;
        }
    }
    if(cont == (*d)->Queue->tam-1){
        (*d)->impossible = 1;
    }

    // Queue
    for (i = 1; i < (*d)->Queue->tam-1; i++)
    {
        if ((*d)->Queue->data[(*d)->Queue->i].elem == val)
        {
            (*d)->Queue->queue++;
            (*d)->Queue->i++;
        }
    }

    // Stack
    if((*d)->Stack->data[(*d)->Stack->tam-1].elem == val){
        (*d)->Stack->stack++;
        (*d)->Stack->tam--;
    }

    // Priority Queue
    for (i = 1; i < (*d)->Priority->tam; i++)
    {
        if((*d)->maior < (*d)->Priority->data[i].elem){
            (*d)->maior = (*d)->Priority->data[i].elem;
            j=i;
        }  
    }
    if(val == (*d)->maior){
        (*d)->Priority->data[j].elem = -999;
        (*d)->Priority->priority++;
    }
}

int main(){

    DS *d;
    int tam, i, n, num;
    int op, data, result=0;
    while (scanf("%d", &tam)!=EOF)
    {
        n = tam;
        create(&d, tam);
        while(n--){

            scanf("%d %d", &op, &data);
            switch (op)
            {
                case 1:
                    insertData(&d, data);
                    break;
                case 2:
                    comparacao(&d, data);
                    d->maior = -999;
                    break;
            }

        }

        if(d->impossible != 1){
            if(d->Stack->stack > d->Queue->queue && d->Stack->stack > d->Priority->priority){
                puts("stack");
            }else if(d->Queue->queue > d->Stack->stack && d->Queue->queue > d->Priority->priority){
                puts("queue");
            }else if(d->Priority->priority > d->Queue->queue && d->Priority->priority > d->Stack->stack){
                puts("priority queue");
            }else{
                puts("not sure");
            }
        }else{
            puts("impossible");
        }
    }
    return 0;
}