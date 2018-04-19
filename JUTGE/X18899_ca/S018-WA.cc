

void im_arbsuma(node_arbreNari* a, node_arbreNari* s, T& suma) const {
  if (a != NULL) {
    s = new node_arbreNari;
    s->seg = vector<node_arbreNari*>(N,NULL);
    suma = a->info;
    for (int i = 0; i < N; ++i) {    
      T r;
      im_arbsuma(a->seg[i],s->seg[i],r);
      suma = suma+r;
    }  
    
    s->info = suma;
  }
  else {
    s = NULL;
    suma = 0;
  }
}


void arbsuma(ArbreNari& asum) const {
/* Pre: cert */
/* Post: asum és l'arbre suma del p.i. */

  T aux;
  delete asum.primer_node;
  im_arbsuma(primer_node,asum.primer_node,aux);
}