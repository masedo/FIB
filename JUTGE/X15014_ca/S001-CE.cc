

int arbre_suma(node_arbre* A, node_arbre* suma) const {
  int ret = 0;
  if (A == NULL) {
    suma = new node_arbre;
    suma->info = 0;
    suma->segE = NULL;
    suma->segD = NULL;
  }
  else {    
    node_arbre* aux;
    aux = new node_arbre;
    int s = arbre_suma(A->segE,aux->segE);
    s += arbre_suma(A->segD,aux->segD);
    aux->info = s;    
    ret = s+(A->info);
    suma = aux;
  }
  return ret;
}
  


void arb_sumes(Arbre<int> &asum) const {
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
  int n = arbre_suma(primer_node,asum.primer_node);  
}