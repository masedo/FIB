#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
using namespace std;


void actualitza_conjunt(Cjt_estudiants& C1, const Cjt_estudiants& C2) {
  for (int i = 1; i <= C2.mida(); ++i) {
    
    if (C2.consultar_iessim(i).te_nota()) {
      
      if (C1.consultar_iessim(i).te_nota()) {
	if (C2.consultar_iessim(i).consultar_nota() > C1.consultar_iessim(i).consultar_nota())
	  C1.modificar_iessim(i,C2.consultar_iessim(i));
      }
      else C1.modificar_iessim(i,C2.consultar_iessim(i));
    }
  }	
}

int main() {
  Cjt_estudiants C1, C2;
  
  C1.llegir();
  C2.llegir();
  
  actualitza_conjunt(C1, C2);

  C1.escriure();
}