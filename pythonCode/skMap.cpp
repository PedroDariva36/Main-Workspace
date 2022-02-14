#include <iostream>
#include <map>
using namespace std;

using ci = pair<char,int>;
map<char, int> counts;

// this code filters a string and return the most repeting cara


int main() {
    string t;
    cin >> t;
  
    for(int i = 0; i < t.size(); ++i) {
        counts[t[i]]++;
    }


    ci tmp  =  {'A', 0};
    for(auto i = counts.cbegin(); i != counts.cend(); ++i){
        if (tmp.second <= i->second){
            tmp = {i->first, i->second};
        }
    }
    cout << tmp.second << endl;
}