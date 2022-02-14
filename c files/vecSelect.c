#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n = 100;
    float a[n];

    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    
    for (int i = 0; i < n; i++){
        if(a[i] <= 10)
           printf("A[%d] = %.1f\n", i,a[i]);
    }
    return 0;
}
