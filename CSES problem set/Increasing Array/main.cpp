#include <iostream>
#include <vector>
using namespace std;

int main(){
    long n;
    vector<unsigned int> x;
    cin >> n;

    long z = 0;
    for (long i = 0; i < n; i++){
        cin >> z;
        x.push_back(z);
    }

    long count = 0;
    long y;
    for (int i = 0; i < n - 1; i++){
        if (x[i+1] < x[i]){
            y = x[i] - x[i+1];
            count += y;
            x[i+1] += y;
        }
    }

    cout << count;
    return 0;
}

