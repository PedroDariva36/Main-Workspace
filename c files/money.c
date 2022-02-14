#include <stdio.h>
#include <math.h>
int money = 0;
int division = 0;
int moduleCache = 0;
int main(int argc, char const *argv[])
{
    scanf("%d", &money);
    printf("%d\n", money);

    if(money >= 100.00){
        moduleCache = money % 100;
        division = money/100;
        money = moduleCache;
        printf("%d nota(s) de R$ 100,00\n", division);
    }
    else
        printf("0 nota(s) de R$ 100,00\n");

    if (money >= 50.00){
        moduleCache = money % 50;
        division = money/50;
        money = moduleCache;
        printf("%d nota(s) de R$ 50,00\n", division);
    }
    else
        printf("0 nota(s) de R$ 50,00\n");

    if (money >= 20.00){
        moduleCache = money % 20;
        division = money/20;
        money = moduleCache;
        printf("%d nota(s) de R$ 20,00\n", division);
    }
    else
        printf("0 nota(s) de R$ 20,00\n");

    if (money >= 10.00){
        moduleCache = money % 10;
        division = money/10;
        money = moduleCache;
        printf("%d nota(s) de R$ 10,00\n", division);
    }
    else
        printf("0 nota(s) de R$ 10,00\n");

    if (money >= 5.00){
        moduleCache = money % 5;
        division = money/5;
        money = moduleCache;
        printf("%d nota(s) de R$ 5,00\n", division);        
    }
    else
        printf("0 nota(s) de R$ 5,00\n");

    if (money >= 2.00){
        moduleCache = money % 2;
        division = money/2;
        money = moduleCache;
        printf("%d nota(s) de R$ 2,00\n", division);
    }
    else
        printf("0 nota(s) de R$ 2,00\n");

    if (money >= 1.00){
        moduleCache = money % 1;
        division = money/1;
        money = moduleCache;
        printf("%d nota(s) de R$ 1,00\n", division);
    }
    else
        printf("0 nota(s) de R$ 1,00\n");
    return 0;
}
