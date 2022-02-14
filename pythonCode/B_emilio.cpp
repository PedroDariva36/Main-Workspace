#include <iostream>
#include <map>
using namespace std;

using cc = pair<char,char>;
map<cc, int> counts;

int main() {

  int N;
  string T;
  cin >> N >> T;
  
  for(int i = 0; i+1 < N; ++i) {
    counts[cc{T[i], T[i+1]}]++;
  }
  
  pair<int, cc> largest = {0, cc{'A', 'A'}};

  for(auto & [k, v] : counts) {
    largest = max(largest, {v, k});
  }
  
  cout << largest.second.first << largest.second.second << '\n';
}