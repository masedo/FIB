node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */

    if (m == NULL) {
      u = NULL;
      a = NULL;
      return NULL;
    }
    else {
      node_llista* P;
      P = new node_llista;
      P->info = m->info;
      P->ant = NULL;
      if (oact == m) a = P;
      node_llista* aux = P;
      while (m->seg != NULL) {
	m = m->seg;
	aux->seg = new node_llista;
	(aux->seg)->ant = aux;
	aux = aux->seg;
	aux->info = m->info;
	if (m == oact) a = aux;
      }
      aux->seg = NULL;
      u = aux;
      if (oact == NULL) a = NULL;
      return P;
    }
}

Llista& operator=(const Llista& original) {
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
      
    if (this != &original) {
      longitud = original.longitud;
      esborra_node_llista(primer_node);
      primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);      
    }
    return *this;
}