#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
 int dia;
 int mes;
 int ano;
} Data;

struct Aluno
{
    char matricula[10];
    char nome[40];
    Data nacimento;
    float nota;
    struct Aluno *next;
};

typedef struct Aluno aluno;

 
aluno createElement(aluno *first,char matricula[40], char nome[10],int dia, int mes, int ano, float nota){
    return *first;
}
aluno deleteElement(aluno *first){
    return *first;
}
aluno clearList(aluno *first){
    aluno *aux = first;
    while (aux != NULL){
        aluno *next = aux-next;
        free(aux);
        *aux = *next; 
    }
}


void printList(aluno *first){
    if (first == NULL){
        printf("Lista Vazia!");
        return;
    }

    for (aluno *aux = first; aux != NULL; aux = aux->next)
       printf("%s, %s, %d/%d/%d, %.6f\n", aux->matricula, aux->nome, aux->nacimento.dia, aux->nacimento.mes, aux->nacimento.ano, aux->nota);
}

void printReverse(aluno *aux){
    if (aux == NULL)
        return;

    printReverse(aux);
    printf("%s, %s, %d/%d/%d, %.6f\n", aux->matricula, aux->nome, aux->nacimento.dia, aux->nacimento.mes, aux->nacimento.ano, aux->nota);
}


int main(int argc, char const *argv[]){   
    aluno *first, *l = NULL;
    
    while(1){
        int op;
        scanf("%d",&op);
        if (op == 0)
            break;
        
        else{
            if (op == 1){
                char matricula[40], nome[10],dataChar[10];
                int data[3];
                float nota;
                scanf("%s",matricula);
                scanf("%s",nome);
                scanf("%s",dataChar);
                scanf("%f",&nota );

                int i = 0;
                char *p = strtok (dataChar, "/");
                while (p != NULL)
                {
                    data[i++] = atoi(p);
                    p = strtok (NULL, "/");
                }

                *first = createElement(first,matricula,nome,data[0],data[1],data[2],nota);
            }

            if (op == 2){
                
            }
            if (op == 3){
                
            }
            if (op == 4){
                
            }
            if (op == 5){
                
            }
            if (op == 6){
                
            }
        }   
    }

    printList(first);
    clearList(first);
    first = NULL;

    return 0;
}

