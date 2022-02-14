#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n = 10;
    int a[n];

    
    scanf("%d", &a[0]);
    for (int i = 1; i < n; i++)
        a[i] = a[i -1] * 2;
    
    for (int i = 0; i < n; i++)
        printf("N[%d] = %d\n", i,a[i]);
    return 0;
}
