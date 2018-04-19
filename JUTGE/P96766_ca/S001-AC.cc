#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool es_palindrom(string s) {
  int n = s.length();
  for (int i = 0; i < n/2; ++i) {
    if (s[i] != s[n-1-i]) return false;
  }
  return true;
}

int main() {
  int n; 
  
  cout << "-----" << endl;
  while (cin >> n and n != 0) {
    vector<string> P;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      if (es_palindrom(s)) P.push_back(s);
    }
    
    int max = 0, siz = P.size();
    for (int i = 0; i < siz; ++i) {
      if (P[i].length() > max) max = P[i].length();
    }
    
    for (int i = 0; i < siz; ++i) {
      if (P[i].length() == max) cout << P[i] << endl;
    }
    
    if (siz == 0) cout << "cap palindrom" << endl;
    
    cout << "-----" << endl;
  }
}
      