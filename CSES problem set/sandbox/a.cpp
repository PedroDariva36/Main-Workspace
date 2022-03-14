#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int n;

void search(int k) {
if (k == n) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    
    cout << endl;
} 
else {
    search(k+1);
    a.push_back(k);
    search(k+1);
    a.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    search(1);

    return 0;
}
