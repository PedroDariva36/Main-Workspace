#include<bits/stdc++.h>
using namespace std;


vector<char> a;
vector<char> b;
vector<vector<int>> matrix;

int solve(int x, int y){
    if (x == 0) return y;
    if (y == 0) return x;
    if (matrix[x][y] != -1) return matrix[x][y];
    

    int cost = 1;
    if(a[x-1] == b[y-1]) cost = 0;
    
    int result = min(min(solve(x-1, y) + 1, solve(x, y-1) + 1),solve(x-1, y-1)+cost);
    //cout << x << " " << y << endl;
    matrix[x][y] = result;
    return result;

}

int main (int argc, char *argv[]){
    char temp;
    while (cin.peek() != '\n') {
        cin >> temp;
        a.push_back(temp);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (cin.peek() != '\n') {
        cin >> temp;
        b.push_back(temp);
    }

    matrix.resize(a.size()+1);
    for (int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < b.size()+1; j++)
            matrix[i].push_back(-1);

    cout << solve(a.size(), b.size())<<endl;
    return 0;
}
