#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > matriu;

matriu producte_matriu(const matriu& a, const matriu& b, int m) {
  matriu M(2,vector<int>(2,0));
  int n = 2;  
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k)
	M[i][j] += a[i][k]*b[k][j];
      M[i][j] %= m;
    } 
  return M;
}


matriu potencia_mod(const matriu& x, int n, int m) {
  matriu M(2,vector<int>(2));
  
  if (n == 0) {
      M[0][0] = 1; M[0][1] = 0;
      M[1][0] = 0; M[1][1] = 1;
      return M;
  } 	
  else {   
    matriu y = potencia_mod(x, n/2, m);
    if (n % 2 == 0) return producte_matriu(y,y,m);
    else return producte_matriu(producte_matriu(y,y,m),x,m);
    } 
}

int fib(int k, int m) {
    if (k < 0) return 0;
    matriu f(2,vector<int>(2));
    f[0][0] = 1; f[0][1] = 1;
    f[1][0] = 1; f[1][1] = 0;
    matriu p = potencia_mod(f,k,m);
    return p[0][0];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << fib(n-1, m)<<endl;
    }
}
        