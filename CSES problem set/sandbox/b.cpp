#include <iostream>
#include <vector>
using namespace std;

vector<int> perm;
bool chosen[10000];
int n;

void search() {
    if (perm.size() == n) {
        for (int i = 0; i < perm.size(); i++)
            cout << perm[i] << " ";
        
        cout << endl;
    } 
    else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            perm.push_back(i);
            search();
            chosen[i] = false;
            perm.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    n = 5;
    search();

    return 0;
}
