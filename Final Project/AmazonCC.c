#include<stdio.h>
#include<stdlib.h>  
#include<string.h>

typedef struct Product product;
typedef struct Cart cart;

struct Product {
   int id;
   char name[30];
   float price;
   int amount;
   struct Product *next, *prev;
};
 
struct Cart {
   product pr;
   int qt_buy;
   cart *next, *prev;
};

typedef struct {
    product *first;
    product *last;
} tuple;

typedef struct {
    cart *first;
    cart *last;
} tupleC;


int countList(product *first){
    if (first == NULL)
        return 0;

    product *aux = first;
    int i = 1;
    while (aux != NULL && aux->next != NULL){
        aux = aux->next;
        i++;
    }
    return i;
}

tuple createElement(tuple b, product pr){
    product *l = NULL;
    product *first = b.first;
    product *last = b.last;
    tuple a;


    l = (product*) malloc(sizeof(product));
    l->id = pr.id;
    strcpy(l->name, pr.name);
    l->price = pr.price;
    l->amount = pr.amount;

    if (first == NULL){
        a.first = l;
        a.last = l;
        return a;
    }

    last->next = l;
    l->prev = last;
    last = l;

    a.first = first;
    a.last = l; 
    return a;
}

tupleC createElementCart(tupleC b, product pr, int qnt){
    cart *l = NULL;
    cart *first = b.first;
    cart *last = b.last;
    tupleC a;


    l = (cart*) malloc(sizeof(cart));
    l->pr.id = pr.id;
    strcpy(l->pr.name, pr.name);
    l->pr.price = pr.price;
    l->pr.amount = pr.amount;
    l->qt_buy = qnt;

    if (first == NULL){
        a.first = l;
        a.last = l;
        return a;
    }

    last->next = l;
    l->prev = last;
    last = l;

    a.first = first;
    a.last = l; 
    return a;
}

product findElement(tuple a, int id){
    product pr;
    if (a.first == NULL){
        printf("Produto não registrado");
        return pr;
    }
    product *aux;
    for (aux = a.first; aux != NULL; aux = aux->next){
        if (id == aux->id){
            pr.id = aux->id;
            strcpy(pr.name, aux->name);
            pr.price = aux->price;
            pr.amount = aux->amount;
            pr.id = aux->id;
            pr.id = aux->id;
        }
    }
    return pr;
}

void updateElementAmount(tuple a, int id, int nAmount){
    for (product *aux = a.first; aux != NULL; aux = aux->next){
        if (aux->id == id){
            aux->amount = nAmount;
        }
    }
}

tuple deleteElement(tuple b, int id){
    product *aux, *l = NULL;
    product *first = b.first;
    product *last = b.last;
    tuple a;
    
    if (first == NULL){
        printf("Nenhum produto registrado\n");
        a.first = first;
        a.last = last;
        return a;
    }

    if(first->id == id){
        if (first->next == NULL){
            free(first);
            a.first = NULL;
            a.last = NULL;
            return a;
        }
        
        aux = first;
        first = first->next;
        first->prev = NULL;
        free(aux);
        a.first = first;
        a.last = last;
        return a;
    }

    if(last->id == id){
        aux = last;
        last = last->prev;
        last->next = NULL;
        free(aux);
        a.first = first;
        a.last = last;
        return a;
    }
    
    for (l = first; l != NULL; l = l->next){
        if(l->id == id){
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

tupleC deleteElementCart(tupleC b, int id){
    cart *aux, *l = NULL;
    cart *first = b.first;
    cart *last = b.last;
    tupleC a;
    
    if (first == NULL){
        printf("Nenhum produto registrado\n");
        a.first = first;
        a.last = last;
        return a;
    }

    if(first->pr.id == id){
        if (first->next == NULL){
            free(first);
            a.first = NULL;
            a.last = NULL;
            return a;
        }
        
        aux = first;
        first = first->next;
        first->prev = NULL;
        free(aux);
        a.first = first;
        a.last = last;
        return a;
    }

    if(first->pr.id == id){
        aux = last;
        last = last->prev;
        last->next = NULL;
        free(aux);
        a.first = first;
        a.last = last;
        return a;
    }
    
    for (l = first; l != NULL; l = l->next){
        if(l->pr.id == id){
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

void clearList(tuple a){
    product *p = a.first;
    while (p != NULL){
        product *aux = p->next;
        free(p);
        p = aux; 
    }
}

void clearCart(tupleC a){
    cart *p = a.first;
    while (p != NULL){
        cart *aux = p->next;
        free(p);
        p = aux; 
    }
}

void printProd( product pr ){
    printf("ID: %d \n", pr.id);
    printf("Nome: %s \n", pr.name);
    printf("Preço: R$ %.2f \n", pr.price);
    printf("Estoque: %d \n", pr.amount);
    printf("\n");
}

void printCart(cart crt){
    printf("ID: %d \n", crt.pr.id);
    printf("Nome: %s \n", crt.pr.name);
    printf("Preço: R$ %.2f \n", crt.pr.price);
    printf("Estoque: %d \n", crt.pr.amount);
    printf("\n");
}

void printByFirst(tuple a){
    product *aux = NULL;
    if (a.first == NULL){
        printf("Nenhum produto registrado\n");
        return;
    }

    for (aux = a.first; aux != NULL; aux = aux->next){
        printProd(*aux);
    }
}

void printByFirstCart(tupleC a){
    cart *aux = NULL;
    if (a.first == NULL){
        printf("Nenhum produto registrado\n");
        return;
    }

    for (aux = a.first; aux != NULL; aux = aux->next){
        printCart(*aux);
    }
}

int main(int argc, char const *argv[]){  
    int id_incremet = 0;
    tuple a;
    a.first = NULL;
    a.last = NULL;

    while(1){
        int op;
        printf("0. Sair\n");
        printf("1. Criar Produto\n");
        printf("2. Excluir Produto\n");
        printf("3. Mostrar Produtors Cadastrados\n");
        printf("4. Buscar Produto\n");
        printf("5. Comprar\n");
        printf("Digite a o codigo da operação: ");
        scanf("%d",&op);
        printf("\n");

        if (op == 0) break;
        
        if (op == 1){
            system("@cls||clear");
            product al;
            al.id = id_incremet;
            id_incremet++;

            printf("Digite o nome do produto: ");
            scanf("%s", al.name);
            printf("Digite o preço do produto: ");
            scanf("%f", &al.price);
            printf("Digite a quantia em estoque do produto: "); 
            scanf("%d", &al.amount);
            al.next = NULL;
            al.prev = NULL;
            a = createElement(a,al);
            system("@cls||clear");
        }

        if (op == 2){
            system("@cls||clear");
            int id;
            printf("Digite o ID do produto para ser excluido:");
            scanf("%d",&id);
            a = deleteElement(a, id);
            system("@cls||clear");
        }   

        if (op == 3){
            system("@cls||clear");
            printf("Produtos Cadastrados:\n");
            printByFirst(a); 
        }

        if (op == 4){
            system("@cls||clear");
            int id;
            printf("Digite o ID do produto:");
            scanf("%d",&id);
            system("@cls||clear");
            product pr = findElement(a, id);
            printProd(pr);
        }
        
        if (op == 5){
            system("@cls||clear");
            tupleC c;
            c.first = NULL;
            c.last = NULL;
            
            while (1){
                int opC;
                printf("0. Cancelar\n");
                printf("1. Adicionar Produto ao Carrinho\n");
                printf("2. Excluir Produto do Carriho\n");
                printf("3. Mostrar Carrinho\n");
                printf("4. Mostrar Produdos Disponiveis\n");
                printf("5. Buscar Produto\n");
                printf("6. Comprar\n\n");
                printf("Digite a o codigo da operação: ");
                scanf("%d",&opC);
                printf("\n");

                if (opC == 0) 
                    break;

                if (opC == 1){
                    int id;
                    int amount;

                    system("@cls||clear");                    
                    printf("Digite o ID do produto: ");
                    scanf("%d", &id);
                    printf("Digite a quantia do produto que voce deseja comprar: "); 
                    scanf("%d", &amount);

                    product pr = findElement(a, id);
                    if(pr.amount >= amount){
                        c = createElementCart(c,pr,amount);
                        system("@cls||clear");
                    }
                    else{
                        system("@cls||clear");
                        printf("Quantia desejada é maior que a disponivel\n\n");
                    }
                    
                }
                
                if (opC == 2){
                    int id;

                    system("@cls||clear");
                    printf("Digite o ID do produto para ser excluido:");
                    scanf("%d",&id);
                    
                    c = deleteElementCart(c, id);
                    system("@cls||clear");
                }
                
                if (opC == 3){
                    system("@cls||clear");
                    printf("Carrinho:\n\n");
                    printByFirstCart(c);
                }

                if (opC == 4){
                    system("@cls||clear");
                    printf("Produtos Cadastrados:\n\n");
                    printByFirst(a); 
                }

                if (opC == 5){
                    system("@cls||clear");
                    int id;
                    printf("Digite o ID do produto:");
                    scanf("%d",&id);
                    system("@cls||clear");
                    product pr = findElement(a, id);
                    printProd(pr);
                    printf("\n");
                }

                if (opC == 6){
                    system("@cls||clear");
                    float totalPrice = 0;
                    printf("Compra Finalizada!\n");
                    for (cart *aux = c.first; aux != NULL; aux = aux->next){
                        totalPrice += aux->pr.price * aux->qt_buy;
                        
                        if(aux->qt_buy == aux->pr.amount) 
                            a = deleteElement(a, aux->pr.id);
                        else
                            updateElementAmount(a, aux->pr.id, aux->pr.amount - aux->qt_buy);
                    }

                    clearCart(c);
                    printf("Total Cobrado: %.2f\n\n", totalPrice);
                    break;
                }
            }
        }
    }
    system("@cls||clear");
    clearList(a);
    printf("\nAté a Proxima!\n");
    return 0;
}
