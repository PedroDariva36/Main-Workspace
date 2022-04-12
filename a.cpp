#include<iostream>
using namespace std;


void solve(int k, int n){
	int a[k];
	int pointer = n % k;
	for(int i = 0; i < k; i ++)
		cin >> a[i];

    for (int i = k - pointer; i < k; i++)
        cout << a[i] << " ";

    for (int i = 0; i < k - pointer; i++)
        cout << a[i] << " ";
} 


int main(){
	int t = 0;
	cin >> t;

	for(int i = 0; i < t; i++){
		int n, k;
		cin >> k >> n;
		solve(k, n);
        cout << endl;
    }   
}