#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;

int n, k;
VE V;

void f(int i, int q) {
  if (q > k or q + n - i < k) return; //si he posat massa uns o massa zeros
  
  if (i == n) {
    for (int j = 0; j < n; ++j) {
        if (j > 0) cout << " ";
        cout << V[j];    
    }
    cout << endl;
    return;
  }  
  V[i] = 0;
  f(i+1,q);
  V[i] = 1;
  f(i+1,q+1);  
}

int main() {
  cin >> n >> k;
  V = VE(n);
  f(0,0);
}
  