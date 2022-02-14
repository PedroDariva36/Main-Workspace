#include <iostream>
using namespace std;

int getUnit(long x){
    if (x > 9)
        return x -((x/10)*10);
    else
        return x;
}

int main()
{
    long n;
    int k;

    cin >> n;
    cin >> k;

    for(int i = 0; i < k; i++){
        if (getUnit(n) == 0)
            n = n / 10;
        else
            n = n - 1;
    }
    cout << n;
    return 0;
}
