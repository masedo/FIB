#include "Cua_estudiants.hh"

void Cua_estudiants::push(const Estudiant &est)
/* Pre: el paràmetre implícit no està ple */
/* Post: el paràmetre implícit és com el paràmetre implícit original amb 
         est afegit com a darrer element */
{
  if (est.te_nota()) {
    if (est.consultar_nota() > notamax) notamax = est.consultar_nota();
  }
  v[t] = est;
  ++n;
  t = (p + n) % MAX;
}

void Cua_estudiants::pop()
/* Pre: el paràmetre implícit no està buit */
/* Post: el paràmetre implícit és com el paràmetre implícit original però 
         sense el primer element afegit al paràmetre implícit original */
{
  bool b = false;
  if (v[p].te_nota() and v[p].consultar_nota() == notamax) {
      notamax = 0;
      b = true;
  }
           
  --n;
  ++p;
  if (p == MAX) p = 0;
  t = (p + n) % MAX;
  
  if (b) {
    if (t > p) {
      for (int i = p; i < t; ++i) 
	if (v[i].te_nota() and v[i].consultar_nota() > notamax) notamax = v[i].consultar_nota();
    }
    else for (int i = t; i < p; ++i) 
      if (v[i].te_nota() and v[i].consultar_nota() > notamax) notamax = v[i].consultar_nota();
  }
}

void Cua_estudiants::escriure() const
/* Pre: cert */
/* Post: s'han escrit pel canal estàndar de sortida els estudiants del
   paràmetre implícit per ordre d'arribada a la cua (del primer al darrer) */
{
  if (t > p) for (int i = p; i < t; ++i) v[i].escriure();
  else {
    for (int i = p; i < MAX; ++i) v[i].escriure();
    for (int i = 0; i < t; ++i) v[i].escriure();
  }
}