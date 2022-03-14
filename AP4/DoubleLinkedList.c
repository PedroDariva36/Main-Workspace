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

struct AlInfo{
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
struct Tuple{
    aluno *first;
    aluno *last;
};

tuple createElement(tuple a, char matPrev[10], alInfo info){
    aluno *l, *aux, *prev = NULL;
    l = (aluno*) malloc(sizeof(aluno));
    strcpy(l->al.matricula, info.matricula);
    strcpy(l->al.nome, info.nome);
    l->al.nacimento.dia = info.nacimento.dia;
    l->al.nacimento.mes = info.nacimento.mes;
    l->al.nacimento.ano = info.nacimento.ano;
    l->al.nota = info.nota;
    l->next = NULL;
    l->prev = NULL;

    if (a.first == NULL){
        a.first = l;
        a.last = l;
        return a;
    }

    if (strcmp(a.first->al.matricula,matPrev) == 0 && a.first->next != NULL){
        aux = a.first->next;
        l->next = aux;
        l->prev = a.first;
        aux->prev = l;
        a.first->next = l;
        return a; 
    }

    if (strcmp(a.last->al.matricula, matPrev) == 0){
        a.last->next = l;
        l->prev = a.last;
        a.last = l;
        return a;
    }

    for (prev = a.first;prev->next != NULL; prev = prev->next){
        if (strcmp(prev->al.matricula,matPrev) == 0){
            aux = prev->next;
            l->next = aux;
            l->prev = prev;
            aux->prev = l;
            prev->next = l; 
            return a; 
        }
    }

    l->next = a.first;
    a.first->prev = l;
    a.first = l;
    return a;
}

tuple deleteElement(tuple a, char matricula[10]){
    aluno *aux, *l = NULL;
    if (a.first == NULL){
        printf("Lista Vazia!\n");
        return a;
    }

    if(strcmp(a.first->al.matricula,matricula) == 0){
        if (a.first->next == NULL){
            free(a.first);
            a.first = NULL;
            a.last = NULL;
            return a;
        }
        
        aux = a.first;
        a.first = a.first->next;
        a.first->prev = NULL;
        free(aux);
        return a;
    }
    if(strcmp(a.last->al.matricula,matricula) == 0){
        aux = a.last;
        a.last = a.last->prev;
        a.last->next = NULL;
        free(aux);
        return a;
    }
    for (l = a.first; l != NULL; l = l->next){
        if(strcmp(l->al.matricula,matricula) == 0){
            aux = l;
            l = aux->prev;
            l->next = aux->next;
            l = aux->next;
            l->prev = aux->prev;
            free(aux);
            return a;
        }
    }
    return a;
}

void printByFirst(aluno *first){
    aluno *aux = NULL;
    if (first == NULL){
        printf("Lista Vazia!\n");
        return;
    }
    for (aux = first; aux != NULL; aux = aux->next) printf("%s, %s, %d/%d/%d, %.2f\n", aux->al.matricula, aux->al.nome, aux->al.nacimento.dia, aux->al.nacimento.mes, aux->al.nacimento.ano, aux->al.nota);
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
    if (first == NULL) return 0;
    aluno *aux = first;
    int i = 1;
    while (aux != NULL && aux->next != NULL){
        aux = aux->next;
        i++;
    }
    return i;
}

int countForDelete(aluno *first,char matricula[10]){
    if (first == NULL) return 0;
    for (aluno *aux = first; aux != NULL; aux = aux->next)
        if (strcmp(aux->al.matricula, matricula)==0) return 1;
    return 0;
}

void clearList(aluno *first){    
    if (first == NULL) return;
    aluno *p = first;
    while (p != NULL){
        aluno *aux = p->next;
        free(p);
        p = aux; 
    }
}

int main(int argc, char const *argv[]){   
    tuple a;
    a.first = NULL;
    a.last = NULL;

    while(1){
        int op;
        scanf("%d",&op);
        if (op == 0)
            break;

        else{
            if (op == 1){
                alInfo al;
                char matriculaPrev[10];
                char dateChar[12];
                int date[3];
                float nota;

                scanf("%s",matriculaPrev);
                scanf("%s %s %s %f",al.matricula,al.nome,dateChar,&nota);

                int i = 0;
                char *p = strtok (dateChar, "/");
                while (p != NULL){
                    date[i++] = atoi(p);
                    p = strtok (NULL, "/");
                }

                al.nacimento.dia = date[0];
                al.nacimento.mes = date[1];
                al.nacimento.ano = date[2];
                al.nota = nota;

                a = createElement(a,matriculaPrev,al);
            }
            if (op == 2){
                char matricula[10];
                scanf("%s",matricula);
                a = deleteElement(a, matricula);
                while (countForDelete(a.first,matricula) == 1) a = deleteElement(a, matricula);
            }   
            if (op == 3) printByFirst(a.first);
            if (op == 4) printByLast(a.last);
        }   
    }
    for (int i = 0; i < countList(a.first); i++)
        printf("*");
    printf("\n\n");
    clearList(a.first);
    return 0;
}