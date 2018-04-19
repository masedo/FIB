#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;

int n;
VE V;

void f(int i) {
  if (i == n) {
    for (int j = 0; j < n; ++j) {
      if (j!=0) cout << " ";
      cout << V[j];
      
    }
    cout << endl;
    return;
  }  
  V[i] = 0;
  f(i+1);
  V[i] = 1;
  f(i+1);  
}

int main() {
  cin >> n;
  V = VE(n);
  f(0);
}
  