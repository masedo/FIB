static T im_suma_cami(node_arbreGen* a) {
  T ret;
  if (a->seg.empty()) ret = a->info;
  else {
    int n = a->seg.size();
    ret = a->seg[0]->info; 
    for (int i = 1; i < n; ++i) {      
      T aux = im_suma_cami(a->seg[i]);
      if (aux >= ret) ret = aux;
    }
    ret += a->info;
  }  
  return ret;
} 
 
 T max_suma_cami() const {
 /* Pre: el parametre implicit no es buit */
 /* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
   
  return im_suma_cami(primer_node);
 }