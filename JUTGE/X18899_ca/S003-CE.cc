

void im_arbsuma(node_arbreNari* a, node_arbreNari* s, T& suma) {
  if (a != NULL) {
    if (a->seg[0] == NULL) {
      s = new node_arbreNari;
      s->info = a->info;
      s->seg = vector<node_arbreNari*>(N,NULL);
      suma = a->info;
    }
    else {
      node_arbreNari* aux;
      aux = new node_arbreNari;
      aux->seg = vector<node_arbreNari*>(N,NULL);
      T sum;
      int i = 0;
      while (i < N and a->seg[i] != NULL) {
	T r;
	im_arbsuma(a->seg[i],aux[i],r);
	sum += r;
      }
      aux->info = sum;
      suma = sum+(a->info);
      s = aux;
    }    
  }
  else s = NULL;
}


void arbsuma(ArbreNari& asum) const {
/* Pre: cert */
/* Post: asum és l'arbre suma del p.i. */

  T aux;
  im_arbsuma(primer_node,asum,aux);
}