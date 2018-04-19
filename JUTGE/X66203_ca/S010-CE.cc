T im_maxim(node_arbreNari* a) const {
  T ret;
  if (a != NULL) {
    ret = a->info;;
    for (int i = 0; i < N; ++i) {
      T aux = im_maxim(a->seg[i]);
      if (aux > ret) ret = aux;
      ++i;  
    }
    return ret;  
  }
}

T maxim() const {
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */

  return im_maxim(primer_node);
}