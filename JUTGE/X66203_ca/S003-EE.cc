T im_maxim(node_arbreNari* a) const {
  T ret;
  if (a->seg.empty()) ret = a->info;
  else {
    ret = im_maxim(a->seg[0]);
    int i = 1;
    while (i < N and a->seg[i] != NULL) {
      T aux = im_maxim(a->seg[i]);
      if (aux > ret) ret = aux;
    }    
  }
  return ret;  
}




T maxim() const {
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */

  return im_maxim(primer_node);
}