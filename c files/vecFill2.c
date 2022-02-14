#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n = 1000;
    int a[n];
    int t = 0;
    
    scanf("%d", &t);
    int count = 0;
    for (int i = 0; i < n; i++){
        if( count == t)
            count = 0;
        a[i] = count;
        count++;
    }
    
    
    for (int i = 0; i < n; i++)
        printf("N[%d] = %d\n", i,a[i]);
    return 0;
}
