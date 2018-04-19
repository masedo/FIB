T im_maxim(node_arbreNari* a) {
  T ret;
  if (a->seg.empty()) ret = a->info;
  else {
    ret = im_maxim(a->seg[0]);
    for (int i = 1; i < N; ++i) {
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