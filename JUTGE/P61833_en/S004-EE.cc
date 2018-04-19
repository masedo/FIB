#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > matriu;


matriu modul_matrius_2_2(matriu x, int m) {
  matriu M(2,vector<int>(2));
  M[0][0] = (x[0][0])%m; 
  M[0][1] = (x[0][1])%m;
  M[1][0] = (x[1][0])%m;
  M[1][1] = (x[1][1])%m;
  return M;
}

matriu producte_matriu_2_2(matriu a, matriu b) {
  matriu M(2,vector<int>(2,0));
  int n = 2;  
  
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
	M[i][j] += a[i][k]*b[k][j];
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
    //matriu mx = modul_matrius_2_2(x,m);
    
    matriu y = potencia_mod(x, n/2, m);
    if (n % 2 == 0) return modul_matrius_2_2(producte_matriu_2_2(y,y),m);
    else return modul_matrius_2_2(producte_matriu_2_2(modul_matrius_2_2((producte_matriu_2_2(y,y)),m),x),m);
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
  