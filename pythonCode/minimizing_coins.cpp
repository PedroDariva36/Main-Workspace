# include <iostream>
#include <vector>

using namespace std; 

const long long mod = 1e9; 
int xAmount = 0;
int nCoins = 0;


int main(){
    cin >> nCoins >> xAmount;
    
    vector<long long> memoryList(xAmount + 1, mod);
    vector<int> coins(nCoins);
    for(int i = 0; i < nCoins; i++){
        cin >> coins[i];
    }


    memoryList[0] = 0;
    for(int i = 1; i <= xAmount; i++){
        for(int j = 0; j < nCoins; j++){
            if (i - coins[j] >= 0){
                memoryList[i] = min(memoryList[i],memoryList[i - coins[j]]+1);
            }
        }
    }

    if (memoryList[xAmount] == mod)
        cout << -1;
    else
        cout << memoryList[xAmount];
}