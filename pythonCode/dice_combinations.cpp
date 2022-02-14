# include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
const uint64_t Mod =1e9 + 7;
int n; 

int main(){
    cin >> n;
    vector<uint64_t> partitionList(n + 1);
    partitionList[0] = 1;
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i - j >= 0){
                partitionList[i] += partitionList[i - j];
                partitionList[i] %= Mod;
            }
            else{
                break;
            }
        }
    }
    cout << partitionList[n];
}
