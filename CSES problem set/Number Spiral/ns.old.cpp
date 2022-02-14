#include<iostream>

using namespace std;


long long getPatern(long long d){
    long long result = 0;
    if (d < 0)
        return 0;
    if (d == 1)
        return 1;
    else {
        result = (d - 1);
        return getPatern(result) + result * 2;
    }
}



long solve(long row, long column){
    if (row == column)
        return getPatern(row);

    else if (column > row){
        if (column % 2 == 0)
            return getPatern(column) + (row - column);
        else
            return getPatern(column) - (row - column);
        
    }
    else{
        if (row % 2 == 0)
            return getPatern(row) + (row - column);
        else
            return getPatern(row) - (row - column);
    }
}

int main(int argc, char const *argv[]){
    
    int n;
    cin  >> n;
    
    for (int i = 0; i < n; i++){
        long x,y;
        cin >> y >> x;     
        cout << solve(y,x)<< endl;
    }
    return 0;
}
