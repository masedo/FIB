
node_arbre* im_sub_arrel(node_arbre* r, const T& x, int& altura) {
  node_arbre* ret = NULL;
  if (r != NULL) {
    if (r->info == x) {
      ret = copia_node_arbre(r);      
    }
    else {
      int alt1, alt2;
      alt1 = alt2 = altura+1;
      node_arbre* r1;      
      node_arbre* r2; 
      r1 = im_sub_arrel(r->segE,x,alt1);
      r2 = im_sub_arrel(r->segD,x,alt2);
      if (r1 != NULL and r2 != NULL) {
	if (alt1 <= alt2) {
	  ret = r1;
	  altura += alt1;
	}
	else {
	  ret = r2;
	  altura += alt2;
	}
      }
      else {
	if (r1 != NULL) {
	  ret = r1;
	  altura += alt1;
	}
	else if (r2 != NULL) {
	  ret = r2;
	  altura += alt2;
	}
      }
    }    
  }
  return ret;
}
  
  



void sub_arrel(Arbre& asub, const T& x) {
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
 
  int altura = 0;
  asub.primer_node = im_sub_arrel(primer_node,x,altura); 
}