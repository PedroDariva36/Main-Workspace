#include <stdio.h>

int l[3];
int m[3];
int swap(int x, int y){
    int temp = l[x];
    l[x] = l[y];
    l[y] = temp;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &l[0],&l[1],&l[2]);
    for (int i = 0; i < 3; i++){
        m[i] = l[i];
    }
    

    if (l[0] > l[2]){
        swap(0,2);
    }
    if (l[0] > l[1]){ 
        swap(0,1);
    }
    if (l[1] > l[2]){
        swap(1,2);
    }



    for (int i = 0; i < 3; i++){
        printf("%d\n", l[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < 3; i++){
        printf("%d\n", m[i]);
    }

    return 0;
}
