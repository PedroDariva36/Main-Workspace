#include <iostream>
#include <vector>
using namespace std;

int findMissing(int x,vector<int> a){
    int bufferSum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        bufferSum = bufferSum + a[i];
    }

    int idealSum = 0;
    for (int i = 1; i < x+1; i++)
    {
        idealSum = idealSum + i;
    }
    
    return idealSum - bufferSum;  
}

int n;
int main(int argc, char const *argv[]){
    cin >> n;
    vector<int> buffer;
    int x;    

    for (int i = 0; i < n - 1; i++){
        cin >> x;
        buffer.push_back(x);
    }
    cout << findMissing(n, buffer);
    return 0;
}
