#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
{
  int dni = est.consultar_DNI();
  int pos = cerca_dicot(vest,0,nest-1,dni);
  
  b = pos < nest and vest[pos].consultar_DNI() == dni;
  
  if (not b) {
    for (int i = nest; i > pos; --i) vest[i] = vest[i-1];
    vest[pos] = est;
    ++nest;
    
    if (imax >= pos) ++imax;
    if (est.te_nota()) {
      if (imax == -1) imax = pos;
      else if (est.consultar_nota() > vest[imax].consultar_nota()) 
	imax = pos;
      else if (est.consultar_nota() == vest[imax].consultar_nota() and
	est.consultar_DNI() < vest[imax].consultar_DNI()) imax = pos;    
    }
  }
}

void Cjt_estudiants::eliminar_estudiants_sense_nota()
/* Pre: cert */
/* Post: el paràmetre implicit no conté cap estudiant sense nota */ 
{
  for (int i = 0; i < nest; ++i) {
    if (not vest[i].te_nota()) {
      int j = i+1;
      while (j < nest and not vest[j].te_nota()) ++j;
      if (j < nest) {
	vest[i] = vest[j];
	Estudiant E;
	vest[j] = E;
      }     
      else nest = i;          
    }
  }
  recalcular_posicio_imax();
}