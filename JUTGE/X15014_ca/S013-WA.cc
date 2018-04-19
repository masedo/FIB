
static void arbre_suma(node_arbre* A, node_arbre* &suma, int &ret) {  
  if (A->segE == NULL and A->segD == NULL) {
    suma = new node_arbre;
    suma->info = 0;
    suma->segE = NULL;
    suma->segD = NULL;
    ret = A->info;
  }
  else {
    node_arbre* aux;
    aux = new node_arbre;
    if (A->segE != NULL and A->segD != NULL) {
      int e, d;
      arbre_suma(A->segE,aux->segE,e);
      arbre_suma(A->segD,aux->segD,d);
      aux->info = e+d;
      suma = aux;
      ret = e+d+(A->info);
    }
    else if (A->segE != NULL) {
      int e;
      arbre_suma(A->segE,aux->segE,e);
      aux->segD = NULL;
      aux->info = e;
      suma = aux;
      ret = e+(A->info);      
    }
    else {
      int d;
      arbre_suma(A->segD,aux->segD,d);
      aux->segE = NULL;
      aux->info = d;
      suma = aux;
      ret = d+(A->info);        
    }
  }
}
  


void arb_sumes(Arbre<int> &asum) const {
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
  if (primer_node != NULL) {
    int n;
    arbre_suma(primer_node,asum.primer_node,n); 
  }
}
  
  