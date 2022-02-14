#include <iostream>
using namespace std;

long x;

void wierd(long n){
    if (n == 1){
        return;
    }
    if (n % 2 == 0)
    {
        n = n/2;
        cout << " " << n;
        wierd(n);
        
    }
    else{
        n = (n*3) + 1;
        cout << " " << n;
        wierd(n);
    }
    
}

int main(int argc, char const *argv[])
{   
    cin >> x;
    cout << x;
    wierd(x);
    return 0;
}
