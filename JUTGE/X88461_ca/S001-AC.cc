#include <iostream>
#include <vector>
using namespace std;


void llegirVector_int(vector<int>& v) {
  int n;
  cin >> n;
  v = vector<int> (n);
  
  for (int i = 0; i < n ; ++i) {
       cin >> v[i];
  }
}

pair<int,int> min_max (const vector<int> &v) {
  pair<int,int> P (v[0],v[0]);
  int s = v.size();
  for (int i = 1; i < s; ++i) {
    if (v[i] < P.first) P.first = v[i];
    if (v[i] > P.second) P.second = v[i];
  }
  return P;
}

int main() {
  
  vector<int> v;
  llegirVector_int(v);
  
  pair<int,int> P = min_max(v);
  
  cout << P.second << " " << P.first << endl;
}
  