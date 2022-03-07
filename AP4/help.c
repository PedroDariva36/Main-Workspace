#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aluno aluno;
typedef struct AlInfo alInfo;
typedef struct Tuple tuple;


typedef struct {
 int dia;
 int mes;
 int ano;
} Date;

struct AlInfo
{
    char matricula[10];
    char nome[40];
    Date nacimento;
    float nota;
};

struct Aluno{
    alInfo al;
    aluno *next;
    aluno *prev;
};

struct Tuple
{
    aluno *first;
    aluno *last;
};

int doesExist(aluno *first, char matPrev[10]){
    if (first == NULL){
        return 0;
    }
    
    for (aluno *aux = first; aux != NULL; aux = aux->next)
        if (strcmp(aux->al.matricula, matPrev))
            return 1;
    
    return 0;

}

aluno clearList(aluno *first){
    aluno *p = first;
    while (p != NULL){
        aluno *aux = p->next;
        free(p);
        p = aux; 
    }
}

void printByFirst(aluno *first){
    aluno *aux = NULL;
    if (first == NULL){
        printf("Lista Vazia!\n");
        return;
    }

    for (aux = first; aux != NULL; aux = aux->next)
       printf("%s, %s, %d/%d/%d, %.2f\n", aux->al.matricula, aux->al.nome, aux->al.nacimento.dia, aux->al.nacimento.mes, aux->al.nacimento.ano, aux->al.nota);
}

void printByLast(aluno *last){
    aluno *aux = NULL;
    if (last == NULL){
        printf("Lista Vazia!\n");
        return;
    }

    for (aux = last; aux != NULL; aux = aux->prev)
       printf("%s, %s, %d/%d/%d, %.2f\n", aux->al.matricula, aux->al.nome, aux->al.nacimento.dia, aux->al.nacimento.mes, aux->al.nacimento.ano, aux->al.nota);
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

tuple createElement(aluno *first,aluno *last, char matPrev[10], alInfo info){
    aluno *l = NULL;
    tuple a;
    printf("%s\n", matPrev);

    l = (aluno*) malloc(sizeof(aluno));
    strcpy(l->al.matricula, info.matricula);
    strcpy(l->al.nome, info.nome);
    l->al.nacimento.dia = info.nacimento.dia;
    l->al.nacimento.mes = info.nacimento.mes;
    l->al.nacimento.ano = info.nacimento.ano;
    l->al.nota = info.nota;
    l->next = NULL;
    l->prev = NULL;

    if (first == NULL){
        a.first = l;
        a.last = l;
        return a;
    }

    
    if (strcmp(first->al.matricula, matPrev) == 0){
        l->next = first;
        first->prev = l;
        first = l;

        a.first = first;
        a.last = last; 
        return a;
    }
    else{
        printf("not First\n");
    }


    if (!strcmp(last->al.matricula, matPrev) == 0){
        last->next = l;
        l->prev = last;
        last = l;

        a.first = first;
        a.last = l; 
        return a;
    }
    else{
        printf("not Last\n");
    }

    for (aluno *aux = first; aux != NULL; aux = aux->next){
        if (!strcmp(aux->al.matricula,matPrev)){
            
            l->next = aux->next;
            l->prev = aux;
            aux->next->prev = l;
            aux->next = l;

            a.first = first;
            a.last = last; 
            return a; 
        }
    }
    printf("matricula não encontrada\n");

    l->next = first;
    first->prev = l;
    first = l;
         
    a.first = first;
    a.last = last; 
    return a;
}

tuple deleteElement(aluno *first,aluno *last, char matricula[10]){
    aluno *aux, *l = NULL;
    tuple a;
    if (first == NULL)
    {
        a.first = first;
        a.last = last;
        return a;
    }
    

    if(strcmp(first->al.matricula,matricula)){
        aux = first;
        first = first->next;
        first->prev = NULL;
        free(aux);
        a.first = first;
        a.last = last;
        return a;
    }
    if(strcmp(last->al.matricula,matricula)){
        aux = last;
        last = last->prev;
        last->next = NULL;
        free(aux);
        a.first = first;
        a.last = last;
        return a;
    }
    for (l = first->next; l->next == NULL; l = l->next){
        if(strcmp(l->al.matricula,matricula)){
            aux = l;
            l = aux->prev;
            l->next = aux->next;
            l = aux->next;
            l->prev = aux->prev;
            free(aux);
            a.first = first;
            a.last = last;
            return a;
        }
    }
    
    a.first = first;
    a.last = last;
    return a;

}



int main(int argc, char const *argv[]){   
    aluno *first = NULL; 
    aluno *last = NULL; 
    aluno *l = NULL;
    
    while(1){
        int op;
        scanf("%d",&op);
        if (op == 0)
            break;
        
        else{
            if (op == 1){
                alInfo al;
                char matriculaPrev[10];
                float nota;
                char dateChar[12];
                int date[3];
                scanf("%s",matriculaPrev);
                scanf("%s %s %s %f",al.matricula,al.nome,dateChar,&nota);
                al.nota = nota;


                int i = 0;
                char *p = strtok (dateChar, "/");
                while (p != NULL){
                    date[i++] = atoi(p);
                    p = strtok (NULL, "/");
                }

                al.nacimento.dia = date[0];
                al.nacimento.mes = date[1];
                al.nacimento.ano = date[2];

                tuple a = createElement(first,last,matriculaPrev,al);
                first = a.first;
                last = a.last;
            }

            if (op == 2){
                char matricula[10];
                scanf("%s",matricula);
                tuple a = deleteElement(first, last, matricula);
                first = a.first;
                last = a.last;
            }   

            if (op == 3)
                printByFirst(first);
            
            if (op == 4)
                printByLast(last);
        }   
    }
    int amount = countList(first);
    for (int i = 0; i < amount; i++)
        printf("*");
    printf("\n"); 
    clearList(first);
    first = NULL;
    return 0;
}

