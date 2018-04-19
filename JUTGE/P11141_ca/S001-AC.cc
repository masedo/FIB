#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Estudiant {
  int dni;
  string nom;
  double nota;
  bool repetidor;
};

void informacio(const vector<Estudiant>& es, double& min, double& max, double& mitj) {
  int s = es.size();
  int cont = 0;
  max = -1;
  min = 10;
  mitj = 0;
  
  for (int i = 0; i < s; ++i) {
    if (not es[i].repetidor and es[i].nota != -1) {
      if (es[i].nota > max) max = es[i].nota;
      if (es[i].nota < min) min = es[i].nota;
      mitj = mitj + es[i].nota;
      ++cont;
    }
  }
  if (cont == 0)
    mitj = min = max = -1;
  else mitj = mitj/double(cont);
}

int main() {}
    
    