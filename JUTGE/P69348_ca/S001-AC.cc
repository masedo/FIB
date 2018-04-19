#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;

int n;
VE V;
VE usat;

void f(int i) {
    if (i == n) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) cout << "(";            
            else cout << ",";
            cout << V[j]+1;
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
  f(0);
}
  