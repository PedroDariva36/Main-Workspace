#include <iostream>
using namespace std;
const long MOD = 1e9 +7; 
 
int main(int argc, char const *argv[]){
    int n,result;
    cin >> n;


    for (int i = 1; i < n; i++)
        result = (result * 2) % MOD;
    cout << result << endl;
    return 0;
}
