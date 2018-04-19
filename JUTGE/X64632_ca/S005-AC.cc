#include "Cua_estudiants.hh"

void Cua_estudiants::push(const Estudiant &est)
/* Pre: el paràmetre implícit no està ple */
/* Post: el paràmetre implícit és com el paràmetre implícit original amb 
         est afegit com a darrer element */
{
  ++n;
  t = (p + n) % MAX;
  if (est.te_nota()) {
    if (est.consultar_nota() > notamax) notamax = est.consultar_nota();
  }
  v[n-1] = est;
}

void Cua_estudiants::pop()
/* Pre: el paràmetre implícit no està buit */
/* Post: el paràmetre implícit és com el paràmetre implícit original però 
         sense el primer element afegit al paràmetre implícit original */
{
  bool b = false;
  if (v[p].te_nota()) {
    if (v[p].consultar_nota() == notamax) {
      b = true;
      notamax = 0;
    }
  }  
  
  for (int i = 0; i < n-1; ++i) {
    v[i] = v[i+1];
    if (b) {
      if (v[i].te_nota()) {
	if (v[i].consultar_nota() > notamax)
	  notamax = v[i].consultar_nota();
      }
    }
  }     
       
  --n;
  t = (p + n) % MAX;
}

void Cua_estudiants::escriure() const
/* Pre: cert */
/* Post: s'han escrit pel canal estàndar de sortida els estudiants del
   paràmetre implícit per ordre d'arribada a la cua (del primer al darrer) */
{
  for (int i = 0; i < n; ++i) v[i].escriure();
}