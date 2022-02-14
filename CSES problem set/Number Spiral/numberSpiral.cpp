#include<iostream>

using namespace std;

int solve(int y, int x ){
    int a = max(y, x);
    int b = min(y, x);

    if (a % 2 ==0){
        

    }
    else{


    }
    


}


int main(int argc, char const *argv[]){
    
    int n;
    cin  >> n;
    
    for (int i = 0; i < n; i++){
        int x,y;
        cin >> y >> x;     
        cout << solve(y,x)<< endl;
    }
    return 0;
}
