#include <list>
using namespace std;



void seleccio(const list<double>& l, list<double>& sel)
/* Pre: l no es buida, sel es buida */
/* Post: sel es el resultat de treure d'l els elements febles en mitjana */
{
  double suma = 0, n = 0;
  for (list<double>::const_iterator it = l.begin(); it != l.end(); ++it) {
    ++n;
    suma += *it;
    double mitjana = suma/n;
    if (*it >= mitjana) sel.insert(sel.end(),*it);
  }  
}
 
