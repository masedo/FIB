
#include <algorithm>
#include "Arbre.hh"
using namespace std;





void arbre_desequilibri(Arbre<int> &a, Arbre<int> &agd, int &prof) {
  if (not a.es_buit()) {
    Arbre<int> a1, a2, agd1, agd2;
    a.fills(a1,a2);
    int prof1, prof2;
    arbre_desequilibri(a1,agd1,prof1);
    arbre_desequilibri(a2,agd2,prof2);
    prof = max(prof1,prof2)+1;
    agd.plantar((prof1-prof2),agd1,agd2);    
  }
  else prof = 0;
}

void arbre_graus_desequilibri(Arbre<int> &a, Arbre<int> &agd)
{
 /* Pre: a=A */
 /* Post: agd es un arbre amb la mateixa estructura que A on cada
    node conte el grau de desequilibri del subarbre d'A corresponent */
 int prof;
 arbre_desequilibri(a,agd,prof);
}

