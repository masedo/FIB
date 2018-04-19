#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;


int main() {
  int m, n;
  double s;
  cin >> m >> n >> s;
  
  vector<Estudiant> Est;
  vector<bool> v(n,false);
  
  for (int i = 0; i < s; ++i) {
    int r; cin >> r;
    v[r-1] = true;
  }
  
  for (int i = 0; i < m; ++i) {
    int dni; cin >> dni;
    Est.push_back(dni);
    
    double suma = 0;
    for (int j = 0; j < n; ++j) {
      double nota; cin >> nota;
      if (v[j]) suma += nota;
    }
    
    Est[i].afegir_nota(suma/s);
  }
  
  for (int i = 0; i < m; ++i) 
    Est[i].escriure();
}
    
    
  


