#include <algorithm>
#include <bits/stdc++.h>
#define n 7

using namespace std;
int grid[n][n];
int cont = 0;
unsigned long recursion = 0;

bool isFree(int i, int j){ 
    if (i < n && i >=0 && j < n && j >= 0 && grid[i][j] == 0) return true;
    return false;
}

bool isDeadend(int i, int j){
    if( i > 0 && i < n-1 && j > 0 && j < n-1){
        int k = 4;

        if (isFree(i,j+1)) k--; 
        if (isFree(i,j-1)) k--;
        if (isFree(i+1,j)) k--;
        if (isFree(i-1,j)) k--;
        
        if (k==2) {
            if (!isFree(i,j-1) && !isFree(i,j+1)) return true;
            if (!isFree(i-1,j) && !isFree(i+1,j)) return true;
        }    
    }
    return false;
}

void search(int s, int i, int j){ 
    recursion++;
    if (j == n-1 && i == n-1 && (s != n*n-1)) return;

    if (s == n*n-1) {
        if (i == n-1 && j == n-1) cont++;
        return;
    }
    
    if (isDeadend(i,j)) return;

    if(i == n-1 || i == 0)
        if (j > 0 && j < n-1)
            if (isFree(i,j-1) && isFree(i,j+1))
                    return;
    
    if(j == n-1 || j == 0)
        if (i > 0 && i < n-1)
            if (isFree(i-1,j) && isFree(i+1,j))
                    return;



    if (isFree(i+1,j)) {
        grid[i][j] = 1;
        search(s+1,i+1,j);
        grid[i+1][j] = 0;
    }
    if (isFree(i-1,j)) {
        grid[i][j] = 2;
        search(s+1,i-1,j);
        grid[i-1][j] = 0;
    }
    if (isFree(i,j+1)) {
        grid[i][j] = 3;
        search(s+1,i,j+1);
        grid[i][j+1] = 0;
    }
    if (isFree(i,j-1)) {
        grid[i][j] = 4;
        search(s+1,i,j-1);
        grid[i][j-1] = 0;
    }
}

int main (int argc, char *argv[])
{
    grid[0][0] = 1;
    search(1,1,0);
    cout<<cont*2<<endl;
    cout<<recursion<<endl;
    return 0;
}
