

void im_arbsuma(node_arbreNari* a, node_arbreNari* s, T& suma) const {
  if (a != NULL) {
    node_arbreNari* aux;
    aux = new node_arbreNari;
    aux->seg = vector<node_arbreNari*>(N,NULL);
    T sum;
    for (int i = 0; i < N; ++i) {    
      T r;
      im_arbsuma(a->seg[i],aux->seg[i],r);
      sum = sum+r;
    }  
    aux->info = sum;
    suma = sum+(a->info);
    s = aux;
  }
  else s = NULL;
}


void arbsuma(ArbreNari& asum) const {
/* Pre: cert */
/* Post: asum és l'arbre suma del p.i. */

  T aux;
  im_arbsuma(primer_node,asum.primer_node,aux);
}