#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
 char node;
 struct stack *next;
} stack;


void inserePilha(stack *stackTop, char node) {
    stack *aux;
    aux = malloc(sizeof(stack));
    aux->node = node;
    aux->next = stackTop->top;
    stackTop->top = aux;
}

void stackPop(StackTop *stackTop) {
    stack *aux;
    char *node = stackTop->top->node;
    aux = stackTop->top;
    printf("%s", node);
    stackTop->top = stackTop->top->next;
    free(aux);
}

void inicializaPilha(StackTop *pilha) {
    pilha->top = NULL;
}

int pilhaVazia(StackTop *pilha) {
    return (pilha->top == NULL);
}

int main() {
    StackTop *stackTop = NULL;
    char node;
    inicializaPilha(&stackTop);
    char string[10];
    scanf("Digite um string[10]: %s \n",  string);

    int i = 0;
    for(i; i < strlen(string); i++) {
        node = string[i];
        inserePilha(&stackTop, node);
    }
    
    for (i; i >= 0; --i)
        removePilha(stackTop);
    

}

