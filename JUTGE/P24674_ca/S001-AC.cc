#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;
typedef vector<string> VS;

int n;
VE usat;
VE V;
VS par;

void f(int i) {
    if (i == n) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) cout << "(";            
            else cout << ",";
            cout << par[V[j]];
            if (j == n-1) cout << ")";
        }
        cout << endl;
        return;
    }  
    for (int j = 0; j < n; ++j) {
        if (not usat[j]) {                
            usat[j] = true;
            V[i] = j;
            f(i + 1);
            usat[j] = false;
        }
    }
}

int main() {
  cin >> n;
  V = VE(n);
  usat = VE(n,false);
  par = VS(n);
  for (int i = 0; i < n; ++i) cin >> par[i];
  f(0);
}
  