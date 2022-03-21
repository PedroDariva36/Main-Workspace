#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    char site[60];
    struct pilha *next;

}Pilha;

Pilha *push(Pilha *topo, char entrada){
    Pilha *novo;
    novo = (Pilha *)malloc(sizeof(Pilha));
    novo->site[60] = entrada;
    novo->next = NULL;
    
    if (topo == NULL){
        topo = novo;
    } else {
        novo->next = topo;
        topo = novo;
    }
    return topo;
}

Pilha *pop(Pilha *topo){
    Pilha *aux=topo;
    if (topo->next == NULL){
        free(topo);
        return NULL;
    }
    topo = topo->next;
    free(aux);
    return topo;
}

void showSite(Pilha *topo){
    Pilha *aux=topo;
    printf("%s\n",aux->site);
}


int main(){

    Pilha *topo = NULL;
    char entrada;

    do{
        scanf("%s", &entrada);

        switch(entrada){
        case 'B':
            if(topo == NULL){
                printf("Vazio\n");
            }
            else {
                topo = pop(topo);
            }
            break;
        case 'E':
            printf("E\n");
        default:
            topo = push(topo, entrada);
            break;


        }

    }
    while (entrada != 'E');

}