#include <stack>
#include "Arbre.hh"


void cami_pref(Arbre<int> &a, stack<int> &c) {
  if (not a.es_buit()) {
    Arbre<int> a1, a2;
    stack<int> c1, c2;
    a.fills(a1,a2);
    cami_pref(a1,c1);
    cami_pref(a2,c2);
    if (c1.size() >= c2.size()) c = c1;
    else c = c2;
    c.push(a.arrel());
  }
}

/* Pre: a=A, c es buida */
/* Post: c conte el cami preferent d'A; si no es buit, el primer element
    del cami es al cim de c */
void cami_preferent(Arbre<int> &a, stack<int> &c) {
  cami_pref(a,c);
  stack<int> p, c1 = c;
  for (int i = 0; i < c.size(); ++i) {
    p.push(c1.top());
    c1.pop();
  }
  c = p;
}




