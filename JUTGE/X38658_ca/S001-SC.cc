#include <stack>
#include "Arbre.hh"


/* Pre: a=A, c es buida */
/* Post: c conte el cami preferent d'A; si no es buit, el primer element
    del cami es al cim de c */
void cami_preferent(Arbre<int> &a, stack<int> &c) {
  if (not a.es_buit()) {
    Arbre<int> a1, a2;
    stack<int> c1, c2;
    a.fills(a1,a2);
    cami_preferent(a1,c1);
    cami_preferent(a2,c2);
    if (c1.size() >= c2.size()) c = c1;
    else c = c2;
    c.push(a.arrel());
  }
}



