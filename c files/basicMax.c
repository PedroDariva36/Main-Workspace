#include <stdio.h>

int a,b;
int main(){
    scanf("%d", &a);
    scanf("%d", &b);
    if (a > b){
        printf("%d", a);
    }
    else if (a < b){
        printf("%d", b);
    }
    else{
        printf("Os números são iguais");
    }
    return 0;
}