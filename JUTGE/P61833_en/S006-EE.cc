#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > matriu;

matriu producte_matriu_2_2(matriu a, matriu b, int m) {
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


matriu potencia_mod(matriu x, int n, int m) {
  matriu M(2,vector<int>(2));
  
  if (n == 0) {
      M[0][0] = 1; M[0][1] = 0;
      M[1][0] = 0; M[1][1] = 1;
      return M;
  } 	
  else {   
    matriu y = potencia_mod(x, n/2, m);
    if (n % 2 == 0) return producte_matriu_2_2(y,y,m);
    else return producte_matriu_2_2(producte_matriu_2_2(y,y,m),x,m);
    } 
}


int main() {
  
  matriu M(2,vector<int>(2));
  int n, m;
  while (cin>>M[0][0]>>M[0][1]>>M[1][0]>>M[1][1]>>n>>m) {
    M = potencia_mod(M,n,m);
    cout << M[0][0] << " " << M[0][1] << endl;
    cout << M[1][0] << " " << M[1][1] << endl;
    cout << "----------" << endl;   
  }
}
  