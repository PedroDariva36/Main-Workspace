#include <stdio.h>

typedef struct complexNumber
{
    double a;
    double bi;
} cn;

cn setCn(double a, double bi){
    cn x;
    x.a = a;
    x.bi = bi;
    return x;
}

cn sumCn(cn x, cn y){
    cn z;
    z.a = x.a + y.a;
    z.bi = x.bi + y.bi;
    return z;
}

void printCn(cn x){
    printf("(%lf + %lfi)\n", x.a, x.bi );
}

int main(int argc, char const *argv[])
{
    cn n,m,o;

    n = setCn(5, 6);
    m = setCn(-1, 2);
    o = sumCn(n, m);
    
    printCn(n);
    printCn(m);
    printCn(o);

    return 0;
}

