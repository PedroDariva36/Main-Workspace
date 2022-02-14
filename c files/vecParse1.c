#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n = 10;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (!(a[i] > 0))
            a[i] = 1;
    }
    
    for (int i = 0; i < n; i++)
        printf("X[%d] = %d\n", i,a[i]);
    return 0;
}
