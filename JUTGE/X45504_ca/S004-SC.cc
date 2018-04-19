#include "ListaPalabras.hh"

void ListaPalabras::anadir_palabra(const Palabra &p)
{
  int l = p.long_pal();
    
  int pos;
  bool trobada;
  buscar_palabra_posicion(p,trobada,pos); 
  
  if (trobada) ++paraules[pos].freq;
  else {
    paraules[nparaules].par = p;  
    paraules[nparaules].freq = 1;
    ++nparaules;
    ++npar_long[l-1];
  }
  
  ++suma_frec_long[l-1];
}

void ListaPalabras::borrar_palabra(const Palabra &p)
{
  int l = p.long_pal(); 
  int pos;
  bool trobada;
  buscar_palabra_posicion(p,trobada,pos);
  if (trobada) {
    if (paraules[pos].freq > 1) --paraules[pos].freq;
    else {
      for (int i = pos; pos < nparaules-1; ++i) 
	paraules[i] = paraules[i+1];
      
      --nparaules;
      --npar_long[l-1];
    }
    --suma_frec_long[l-1];
  }  
}

void ListaPalabras::buscar_palabra_posicion(const Palabra &p, bool &b, int &i) const
{
  b = false;
  i = 0;
  while (i < nparaules and not b) {
    if (paraules[i].par.iguales(p)) b = true;  
    ++i;
  }
  if (b) --i;
}