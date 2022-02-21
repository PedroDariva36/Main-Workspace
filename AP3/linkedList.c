#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aluno aluno;

typedef struct {
 int dia;
 int mes;
 int ano;
} Data;

struct Aluno{
    char matricula[10];
    char nome[40];
    Data nacimento;
    float nota;
    aluno *next;
};

aluno* createElement(aluno *first,char matricula[10], char nome[40],int dia, int mes, int ano, float nota){
    aluno *last,*l = NULL;

    l = (aluno*) malloc(sizeof(aluno));
    strcpy(l->matricula, matricula);
    strcpy(l->nome, nome);
    l->nacimento.dia = dia;
    l->nacimento.mes = mes;
    l->nacimento.ano = ano;
    l->nota = nota;
    l->next = NULL;

    if (first == NULL)
        return l;
    
    aluno *aux = first;
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = l;
    return first;
}


aluno* deleteElement(aluno *first, char matricula[10]){
    aluno *aux, *prev = NULL;
    prev = first;

    for (aux = first; aux != NULL; aux = aux->next){
        if (strcmp(aux->matricula, matricula) == 0){
            if (aux == first){
                first = aux->next;
                free(aux);
                return first;
            }
            prev->next = aux->next;
            free(aux);
            return first;
        }
        prev = aux;
    }
    return first;
}


aluno clearList(aluno *first){
    aluno *p = first;
    while (p != NULL){
        aluno *aux = p->next;
        free(p);
        p = aux; 
    }
}


void printList(aluno *first){
    if (first == NULL){
        printf("Lista Vazia!\n");
        return;
    }

    for (aluno *aux = first; aux != NULL; aux = aux->next)
       printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nacimento.dia, aux->nacimento.mes, aux->nacimento.ano, aux->nota);
}


int countList(aluno *first){
    if (first == NULL)
        return 0;
    aluno *aux = first;
    int i = 1;
    while (aux != NULL && aux->next != NULL){
        aux = aux->next;
        i++;
    }
    return i;
}

void printReverse(aluno *aux){
    if (aux == NULL)
        return;

    printReverse(aux->next);
    printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nacimento.dia, aux->nacimento.mes, aux->nacimento.ano, aux->nota);
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
                char matricula[10], nome[40],dataChar[10];
                int data[3];
                float nota;
                scanf("%s %s %s %f",matricula,nome,dataChar,&nota);
                // scanf("%s",matricula);
                // scanf("%s",nome);
                // scanf("%s",dataChar);
                // scanf("%f",&nota );

                int i = 0;
                char *p = strtok (dataChar, "/");
                while (p != NULL){
                    data[i++] = atoi(p);
                    p = strtok (NULL, "/");
                }
                
                first = createElement(first,matricula,nome,data[0],data[1],data[2],nota);
            }

            if (op == 2){
                char matricula[10];
                scanf("%s",matricula);
                deleteElement(first, matricula);
            }
            if (op == 3){
                printList(first);
            }
            if (op == 4){
                if (first == NULL)
                    printf("Lista Vazia!\n");
                else
                    printReverse(first);
            }
            if (op == 5){
                printf("%d\n",countList(first));
            }
        }   
    }
    int amount = countList(first);
    for (int i = 0; i < amount; i++)
        printf("-");
    printf("\n"); 
    clearList(first);
    first = NULL;

    return 0;
}

