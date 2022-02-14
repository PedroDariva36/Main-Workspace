#include<iostream>
using namespace std;

int main()
{   
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int Le,v,l,r;
        cin >> Le;
        cin >> v;
        cin >> l;
        cin >> r;

        int total = Le / v;
        int totalR = (r -1) / v;
        int totalL = l/v;

        cout << total - totalL + totalR;

    }
    return 0;
}