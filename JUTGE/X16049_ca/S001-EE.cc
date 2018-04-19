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
  while (aux != NULL and P != NULL) {
    if (aux->info <= x) {
      if (aux == P) {
	aux = aux->seg;
	P = P->seg;
      }
      else {
	bool i = (primer_node == P);
	//el fiquem abans que P
	node_llista* k = aux->seg;
	aux->seg = P;
	aux->ant = P->ant;
	P->ant = aux;	
	if (i) primer_node = aux;
	aux = k;
      }
    }
    else aux = aux->seg;
  }
  act = P;
}

  
  
  
  
