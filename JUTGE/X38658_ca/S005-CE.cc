#include <stack>
#include "Arbre.hh"
#include "ArbIOint.hh"
#include "PilaIOint.hh"
#include <iostream>
using namespace std;


void cami_pref(Arbre<int> &a, stack<int> &c, int &el) {
  if (not a.es_buit()) {
    int arrel = a.arrel();
    Arbre<int> a1, a2;
    stack<int> c1, c2;
    a.fills(a1,a2);
    int el1, el2;
    cami_pref(a1,c1,el1);
    cami_pref(a2,c2,el2);
    if (el1 >= el2) c = c1;
    else c = c2;
    el = el1+el2+1;
    c.push(arrel);
  }
  else el = 0;
}

/* Pre: a=A, c es buida */
/* Post: c conte el cami preferent d'A; si no es buit, el primer element
    del cami es al cim de c */
void cami_preferent(Arbre<int> &a, stack<int> &c) {
  int elements = 0;
  cami_pref(a,c,elements);
}
