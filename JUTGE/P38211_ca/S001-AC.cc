#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;

int n;
VE V;
VE column, dia1, dia2;
bool primer = false;

int f(int i) {
    if (primer) return 0;
    if (i == n) {
      for (int j = 0; j < n; ++j) {
          for (int k = 0; k < n; ++k) {
              if(k == V[j]) cout << "Q";
              else cout << ".";
          }
          cout << endl;
      }
      primer = true;
      return 1;
  }
    
  int res = 0;
  for (int j = 0; j < n; ++j) {
    int d1 = i + j;
    int d2 = i -j + n -1;
    if (not column[j] and not dia1[d1] and not dia2[d2]) {
      column[j] = dia1[d1] = dia2[d2] = true;
      V[i] = j;
      res += f(i+1);
      column[j] = dia1[d1] = dia2[d2] = false;
    }
  }
  return res;
}

int main() {
  cin >> n;
  V = VE(n);
  dia1 = dia2 = VE(2*n -1,false);
  column = VE(n,false);  
  if (not f(0)) cout << "NO SOLUTION" << endl;
}