
#include "Arbre.hh"

using namespace std;


int n_diferencies(Arbre<int> &a, Arbre<int> &b) {
  int n;
        if (a.es_buit() and b.es_buit()) n = 0;
        else if (a.es_buit() and not b.es_buit()) {
                Arbre<int> aux1,aux2;
                b.fills(aux1,aux2);
                return 1+n_diferencies(aux1,aux2);
        }
        else if (not a.es_buit() and b.es_buit()) {
                Arbre<int> aux1,aux2;
                a.fills(aux1,aux2);
                return 1+n_diferencies(aux1,aux2);
        }
        else {
                Arbre<int> ae,ad,be,bd;
                a.fills(ae,ad);
                b.fills(be,bd);
                n = n_diferencies(ae,be)+n_diferencies(ad,bd);
        }
        return n;
}

bool quasi_coincidents(Arbre<int> &a, Arbre<int> &b) {
  int nc = n_diferencies(a,b);
  return nc <= 1;
}
  

