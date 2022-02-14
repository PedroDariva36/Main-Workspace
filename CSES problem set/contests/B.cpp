#include<iostream>
#include<vector>
using namespace std;

void solve(){
    if( sum % n == 0){
            int y = sum/n;
            int k = 0;
            for ( i = 0; i < n; i++){
                if (a[i] > y)
                {
                    k++;
                }   
            }
            cout << k << endl;
        }
        else{
            cout << -1 << endl;
        }
}


vector<int> a;
int t;
int main(int argc, char const *argv[]){
    cin >> t;
    for (int i = 0; i < t; i++){   
        
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            sum = sum + x;
            a.push_back(x);
        }

        
    }
}
