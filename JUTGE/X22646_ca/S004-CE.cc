void trenat(Cua &c) {
 /* Pre: p.i. = C1, c = C2 */
 /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
  
  longitud += c.longitud;
  if (c.longitud >= longitud) ultim_node = c.ultim_node;  
  c.ultim_node = NULL;
  if (n1 == NULL) primer_node = c.primer_node;
  c.primer_node = NULL;
  
  node_cua* n1 = primer_node;
  node_cua* n2 = c.primer_node;
  while (n1 != NULL and n2 != NULL){
    node_cua* aux = n2;
    n2 = n2->seguent;
    aux->seguent = n1->seguent;
    n1->seguent = aux;
    if (aux->seguent != NULL) n1 = aux->seguent;
    else {
      n = NULL;
      aux->seguent = n2;
    }
  }
}