T im_maxim(node_arbreNari* a) const {
  T ret = a->info;;
  int i = 0;
  if (not a->seg.empty()) {
    while (a->seg[i] != NULL and i < N) {
      T aux = im_maxim(a->seg[i]);
      if (aux > ret) ret = aux;
      ++i;
    }
  }
  return ret;  
}

T maxim() const {
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */

  return im_maxim(primer_node);
}