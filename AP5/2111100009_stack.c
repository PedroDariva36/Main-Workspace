#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack stack;
struct Stack{
    char s[60];
    stack *next; 
};

stack* stack_push(char string[60], stack *first){
    stack *l = NULL;    
    
    l = (stack*) malloc(sizeof(stack));
    strcpy(l->s, string);

    if (first == NULL){
        l->next = NULL;
        return l;
    }

    l->next = first;
    first = l;
    return first;
}

stack* stack_pop(stack *first){
    stack* aux;
    if (first == NULL){
        printf("Vazio\n");
        return first;
    }

    if (first->next == NULL){
        printf("%s\n", first->s);
        aux = first;
        free(first);
        return NULL;
    }

    aux = first;
    first = first->next;
    printf("%s\n", aux->s);
    free(aux);
    return first;
}

int countList(stack *first){
    if (first == NULL) return 0;
    
    stack *aux = first;
    int i = 1;
    while (aux != NULL && aux->next != NULL){
        aux = aux->next;
        i++;
    }
    return i;
}

void clearList(stack *first){
    stack *p = first;
    while (p != NULL){
        stack *aux = p->next;
        free(p);
        p = aux; 
    }
}


int main(int argc, char const *argv[]){
    stack *first = NULL; 
    while (1){
        char string[60];
        scanf("%s",string);

        if (strcmp(string, "B") == 0){
            first = stack_pop(first);
            continue;
        }
        
        if (strcmp(string, "E") == 0) break;
        first = stack_push(string,first);
    }

    int amount = countList(first);
    clearList(first);
    if (amount > 0){
        for (int i = 0; i < amount; i++)
            printf("@");
        printf("\n"); 
    }
    else printf("!\n");
    return 0;
}


