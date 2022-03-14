#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long IsPrimeV1(long long n)
{
    long long i;
    for (i=2;i<n;i++)
        if (n%i==0)
            return 0;
    return 1;
}

long long IsPrimeV2(long long n)
{
    long long i;
    for (i=2;i<n/2;i++)
        if (n%i==0)
            return 0;
    return 1;
}

long long IsPrimeV3(long long n)
{
    long long i;
    for (i=2;i<sqrt(n);i++)
        if (n%i==0)
            return 0;
    return 1;
}


int main(int argc, char const *argv[])
{
    long long j;
    scanf("%lld",&j);
    if (IsPrimeV3(j)){
        printf("%lld is prime",j);
        return 0;
    }

    printf("%lld is not prime",j);
    return 0;
}
