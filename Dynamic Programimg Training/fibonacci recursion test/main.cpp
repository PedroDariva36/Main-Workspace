#include <iostream>
#include <vector>

using namespace std;
using ll = long long;



int main(int argc, char const *argv[])
{
    vector<ll> buffer;
    int n;
    buffer.push_back(0);
    buffer.push_back(1);
    
    cin >> n;
    if (n == 0 or n == 1){
        cout << 1 << endl;
        return 0;   
    }


    for (int i = 2; i < n; i++)
    {
        buffer.push_back(buffer[i-1] + buffer[i-2]);
    }


        cout << buffer[buffer.size()]<< endl;

}
