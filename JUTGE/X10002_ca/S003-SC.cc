void esborrar_tots(const T& x) {
 /* Pre: parametre implicit = P */
 /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
    resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
    referenciava a una aparicio d'x, passa a referenciar al primer element
    diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
    a la dreta el tot); en cas contrari, el punt d'interes no canvia */
 
  
  node_llista* n = primer_node;  
  while (n != NULL) {
    if (n->info == x) {
      if (n == primer_node and n == act and n == ultim_node) {
        primer_node = act = ultim_node = NULL;
        delete n;         
      }
      else if (n == primer_node and n == act) {
        primer_node = act = n->seg;
        delete n;
        n = primer_node; 
        n->ant = NULL;
      }
      else if (n == primer_node and n == ultim_node) {
	primer_node = ultim_node = NULL;
        delete n;
      }
      else if (n == primer_node) {
        primer_node = n->seg;
        delete n;
        n = primer_node;
        n->ant = NULL;
      }
      else if (n == act and n == ultim_node) {
        act = ultim_node = n->ant;
        delete n;
        n = act;
        n->seg = NULL;
      }
      else if (n == act) {
        act = n->seg;
        n->ant->seg = act;
        act->ant = n->ant;
        delete n;
        n = act;       
      }
      else if (n == ultim_node) {
        ultim_node = n->ant;
        ultim_node->seg = NULL;
        delete n;
        n = ultim_node; 	  
      }
      else {
        node_llista* aux = n->seg;
        n->ant->seg = n->seg;
        n->seg->ant = n->ant;
        delete n;
        n = aux;	  
      }  
      --longitud;
    }     
    n = n->seg;  
  }
}