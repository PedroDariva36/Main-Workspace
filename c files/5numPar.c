#include<stdio.h>
int main(int argc, char const *argv[])
{
    
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        int a;
        scanf("%d", &a);
        if (a % 2 == 0)
            count++;
    }
    printf("%d valores pares\n", count);
    return 0;
}
