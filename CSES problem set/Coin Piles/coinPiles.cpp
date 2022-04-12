#include <iostream>
using namespace std;

void solve(int a, int b){
    if (a == 0 and b == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (a != 0)
    {
        /* code */
    }
    
        

    if (a == b && a % 3 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    
    if (a == 2*b){
        cout << "YES" << endl;
        return;
    }

    if (a%2 == 0 && b%2 == 0)
    {
        cout << "NO" << endl;
        return;
    }
    

    if ((a - b)%2 == 0 && a != b)
    {
        cout << "YES"<< endl;;
        return;
    }
    cout << "NO" << endl;
    
}

int main(int argc, char const *argv[])
{
    int t,a,b = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        cin >> b;

        solve(max(a,b),min(a,b));
    }
    


    return 0;
}


