#include "Arbre.hh"

void arbre_suma(node_arbre* A, node_arbre* suma, int &ret) {  
  if (A == NULL) {
    suma = new node_arbre;
    suma->info = 0;
    suma->segE = NULL;
    suma->segD = NULL;
    ret = 0;
  }
  else {    
    node_arbre* aux;
    aux = new node_arbre;
    int s;
    arbre_suma(A->segE,aux->segE,s);
    int r;
    arbre_suma(A->segD,aux->segD,r);
    aux->info = s+r;    
    ret = s+(A->info);
    suma = aux;
  }
}
  


void arb_sumes(Arbre<int> &asum) const {
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
  int n;
  arbre_suma(primer_node,asum.primer_node,n); 
}