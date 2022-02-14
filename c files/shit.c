#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){
    
    int n;
    char x[3];
    char y[4];
    char z[3];

     
    scanf("%d",&n);
    char str[14];
    int t = 0;
    
    for (int i = 0; i < n; i++){
        int t=0;
        
        scanf("%s",str);
        strncpy(x, str+2, 2);
        strncpy(y, str+5, 3);
        strncpy(z, str+11, 2);
        
        x[2]='\0';
        y[3]='\0';
        z[2]='\0';

        t = atoi(x) + atoi(y) + atoi(z);
        printf("%d\n",t);

    }
    return 0;

}