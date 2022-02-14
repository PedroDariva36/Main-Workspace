#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d",&n);
    int a[n];

    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] < a[pos])
            pos = i;
    }

    printf("Menor valor: %d\n", a[pos]);
    printf("Posicao: %d\n", pos);

}
