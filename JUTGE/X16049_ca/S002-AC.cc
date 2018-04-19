void  reorganitzar_in(const T& x) 
/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels 
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */
{
  node_llista* aux = primer_node;
  node_llista* P = primer_node;
  while (aux != NULL) {
    node_llista* r = aux->seg;
    if (aux->info <= x) {
      
      if (aux == P) P = P->seg;
      else if (r == NULL) {
	ultim_node = aux->ant;
	aux->ant->seg = NULL;
	if (P != primer_node) {
	  aux->seg = P;
	  aux->ant = P->ant;
	  P->ant->seg = aux;
	  P->ant = aux;	  	  
	}
	else {
	  aux->seg = P;
	  aux->ant = NULL;
	  P->ant = aux;	  
	  primer_node = aux;
	}
      }
      else {
	if (P != primer_node) {
	  aux->seg->ant = aux->ant;
	  aux->ant->seg = aux->seg;
	  aux->seg = P;
	  aux->ant = P->ant;
	  P->ant->seg = aux;
	  P->ant = aux;	  
	}
	else {
	  aux->seg->ant = aux->ant;
	  aux->ant->seg = aux->seg;
	  aux->seg = P;
	  aux->ant = NULL;
	  P->ant = aux;
	  primer_node = aux;
	}
      }
    }
    aux = r;
  }
  act = P;
}