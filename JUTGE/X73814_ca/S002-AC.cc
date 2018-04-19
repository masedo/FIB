#include "Estudiant.hh"
#include <vector>
using namespace std;


void llegir_estudiants(vector<Estudiant>& v, int n) {
  for (int i = 0; i < n; ++i) 
    v[i].llegir();
}

void simplifica_estudiants(const vector<Estudiant>& v1, vector<Estudiant>& v2, int n) {
  v2.push_back(Estudiant(v1[0].consultar_DNI()));                                                                                                  
  
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (v1[i].consultar_DNI() == v2[j].consultar_DNI()) {
      if (v1[i].te_nota()) {
	if (v2[j].te_nota()) {
	  if (v1[i].consultar_nota() > v2[j].consultar_nota())
	    v2[j].modificar_nota(v1[i].consultar_nota());
	}
	else v2[j].afegir_nota(v1[i].consultar_nota());
      }
    }
    else {
      ++j;
      v2.push_back(Estudiant(v1[i].consultar_DNI()));
      if (v1[i].te_nota()) v2[j].afegir_nota(v1[i].consultar_nota());
    }
  }      
}

void escriu_estudiants_simplificats(const vector<Estudiant>& v) {
  int s = v.size();
  for (int i = 0; i < s; ++i) 
    v[i].escriure();
}

int main() {
  int n;
  cin >> n;
  
  vector<Estudiant> v1(n);
  llegir_estudiants(v1,n);
  
  vector<Estudiant> v2;
  simplifica_estudiants(v1,v2,n);
  
  escriu_estudiants_simplificats(v2);
}
  
  
  
  
  
  
