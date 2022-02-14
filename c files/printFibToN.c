#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);

    if (n == 1)
        printf("0\n");
    if (n == 2)
        printf("0 1\n");
    
    if (n > 2){
        printf("0 1");
        int a = 0;
        int b = 1;
        int c;
        for (int i = 3; i < n+1; i++){
            c = a + b;
            printf(" %d", c);
            a = b;
            b = c;
        }
        printf("\n")
    }
    
    return 0;
}
