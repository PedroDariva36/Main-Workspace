#include <iostream>
#include <map>
using namespace std;
using ci = pair<char,int>;

int main() {
    string t;
    cin >> t;
    
    ci largest = {'A' ,0};
    ci temp = {'A' ,0};
    for(int i = 0; i < t.size(); ++i) {
        if(temp.first == t[i])
            temp.second++;
        else{
            if (largest.second < temp.second)
                largest = temp;
            temp = {t[i], 1};
        }
    }

    cout << max(largest.second, temp.second);
}