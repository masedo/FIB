

int im_freq(node_arbreGen* a, const T& x) const {
  int ret = 0;
  if (a != NULL) {
    if (a->seg.empty()) {
      if (a->info == x) ++ret;
    }
    else {
      for (int i = 0; i < a->seg.size(); ++i) {
	int r = im_freq(a->seg[i],x);
	ret += r;
      }
    }    
  }
  return ret;
}

int freq(const T& x) const {
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
  return im_freq(primer_node,x);
}