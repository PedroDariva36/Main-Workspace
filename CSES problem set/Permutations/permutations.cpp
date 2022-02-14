#include<iostream>
#include<vector>
using namespace std;


vector<int> even;
vector<int> odd;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    if (n == 1)
        cout << 1;
    else if (n == 4)
        cout << "2 4 1 3";

    else if (n > 4){ 
        for (int i = 5; i < n+1; i++){
            if (i % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }

        for (auto itr = even.end() - 1;itr != even.begin() - 1; itr--)
            cout << *itr << " ";
        cout << "2 4 1 3 ";
        for (auto itr = odd.end() - 1;itr != odd.begin() - 1; itr--)
            cout << *itr << " ";
        return 0;
    }
    else
        cout << "NO SOLUTION";
}
