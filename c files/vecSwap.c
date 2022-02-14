#include<stdio.h>

const int n = 4;
int a[4];

void swap(int o, int p){
    int temp = a[o];
    a[o] = a[p];
    a[p] = temp;
}

int main(int argc, char const *argv[])
{

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < n/2; i++)
        swap(i,n - i -1);

    for (int i = 0; i < n; i++)
        printf("N[%d] = %d\n",i,a[i]);
    
    return 0;
}
