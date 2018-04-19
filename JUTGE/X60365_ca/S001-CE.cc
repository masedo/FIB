

bool im_buscar(node_arbreGen* a, const T& x) {
  bool ret = false;
  if (a != NULL) {
    if (a->seg.empty()) ret = (a->info == x);
    else {
      for (int i = 0; i < a->seg.size(); ++i) {
	if (im_buscar(a->seg[i],x)) return true;
      }
    }
  }
}


bool buscar(const T& x) const {
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */

  return im_buscar(primer_node,x);
}