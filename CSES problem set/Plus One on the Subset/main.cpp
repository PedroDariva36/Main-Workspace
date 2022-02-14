#include <iostream>
#include <vector>

using namespace std;

long solve(vector<long> x){
    long highest = x[0];
    long lowest = x[0];
    
    for (int i = 0; i < x.size(); i++){
        if(x[i] > highest)
            highest = x[i];

        if(x[i] < lowest)
            lowest = x[i];
    }
    return highest - lowest;
}


int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        vector<long> a;
        for (int i = 0; i < n; i++){
            int c;
            cin >> c;
            a.push_back(c);
        }
        cout << solve(a) << endl;  
    }
    return 0;
}