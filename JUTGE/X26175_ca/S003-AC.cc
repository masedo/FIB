#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
{
  int dni = est.consultar_DNI();
  int pos = cerca_dicot(vest,0,nest-1,dni);
  
  if (pos < nest) b = vest[pos].consultar_DNI() == dni;
  else b = false;
  
  if (not b) {
    for (int i = nest; i > pos; --i) 
      vest[i] = vest[i-1];
    
    vest[pos] = est;
    ++nest;
    
    if (est.te_nota())
      incrementar_interval(est.consultar_nota());
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */
{
  int pos = cerca_dicot(vest,0,nest-1,dni);
  
  if (pos < nest) b = vest[pos].consultar_DNI() == dni;
  else b = false;
  
  if (b) {
    if (vest[pos].te_nota()) 
      decrementar_interval(vest[pos].consultar_nota());
    
    for (int i = pos; i < nest-1; ++i)
      vest[i] = vest[i+1];
    
    --nest;
  }
}