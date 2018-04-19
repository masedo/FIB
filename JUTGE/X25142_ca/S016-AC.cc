static T im_suma_cami(node_arbreGen* a) {
  T ret = a->info;
  if (not a->seg.empty()) {
    int n = a->seg.size();
    T max = im_suma_cami(a->seg[0]); 
    for (int i = 1; i < n; ++i) {      
      T aux = im_suma_cami(a->seg[i]);
      if (aux > max) max = aux;
    }
    ret += max;
  }  
  return ret;
} 
 
 T max_suma_cami() const {
 /* Pre: el parametre implicit no es buit */
 /* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
   
  return im_suma_cami(primer_node);
 }