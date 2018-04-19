
static void arbre_suma(node_arbre* A, node_arbre* &suma) {  
  if (A->segE == NULL and A->segD == NULL) {
    suma = new node_arbre;
    suma->info = 0;
    suma->segE = NULL;
    suma->segD = NULL;
  }
  else {
    node_arbre* aux;
    aux = new node_arbre;
    if (A->segE != NULL and A->segD != NULL) {
      arbre_suma(A->segE,aux->segE);
      arbre_suma(A->segD,aux->segD);
      aux->info = (A->info)+(aux->segE)+(aux->segD);
      suma = aux;
    }
    else if (A->segE != NULL) {
      arbre_suma(A->segE,aux->segE);
      aux->segD = NULL;
      aux->info = (A->info)+(aux->segE);
      suma = aux;      
    }
    else {
      arbre_suma(A->segD,aux->segD);
      aux->segE = NULL;
      aux->info = (A->info)+(aux->segD);
      suma = aux;       
    }
  }
}
  


void arb_sumes(Arbre<int> &asum) const {
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
  if (primer_node != NULL) {
    arbre_suma(primer_node,asum.primer_node); 
  }
  else asum.primer_node = NULL;
}
  
  