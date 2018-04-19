static node_llista* copia_node_l(node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
    node_llista* n;
    if (m==NULL) {n=NULL; u=NULL; a=NULL;}
    else {
      n = new node_llista;
      n->info = m->info;
      n->ant=NULL;
      n->seg = copia_node_llista(m->seg, oact, u, a);
      if (n->seg == NULL) u = n; 
      else n->seg->ant = n;
      if (m == oact) a = n;
    }
    return n;
}

Llista reorganitzar_out(const T& x) const {
/* Pre: cert */
/* Post: el resultat és una llista que conté els mateixos 
elements que el p.i. tal que tots els més petits o iguals 
que x al p.i. precedeixen als més grans que x al p.i. però 
sempre respectant l'ordre que hi havia entre ells al p.i. 
L'element actual de la llista retornada és el primer dels 
més grans que x, si existeix, sinó es situa a la detra del 
tot. El p.i. no es modifica */
 
  //fem una copia del P.I. a L2
  Llista<int> L2;
  L2.longitud = longitud;
  L2.primer_node = copia_node_l(primer_node,act,L2.ultim_node,L2.act);
  
  
  
  
  //reorganitzem
  node_llista* aux = L2.primer_node;
  node_llista* P = L2.primer_node;
  while (aux != NULL) {
    node_llista* r = aux->seg;
    if (aux->info <= x) {
      
      if (aux == P) P = P->seg;
      else if (r == NULL) {
	L2.ultim_node = aux->ant;
	aux->ant->seg = NULL;
	if (P != L2.primer_node) {
	  aux->seg = P;
	  aux->ant = P->ant;
	  P->ant->seg = aux;
	  P->ant = aux;	  	  
	}
	else {
	  aux->seg = P;
	  aux->ant = NULL;
	  P->ant = aux;	  
	  L2.primer_node = aux;
	}
      }
      else {
	if (P != L2.primer_node) {
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
	  L2.primer_node = aux;
	}
      }
    }
    aux = r;
  }
  L2.act = P;
  return L2;
}