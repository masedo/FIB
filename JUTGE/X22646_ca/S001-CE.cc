void trenat(Cua &c) {
 /* Pre: p.i. = C1, c = C2 */
 /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
  
  longitd += c.longitud;
  node_cua* n1 = primer_node;
  node_cua* n2 = c.primer_node;
  c.primer_node = NULL;
  while (n1 != ultim_node and c.longitud > 0) {
    node_cua* aux = n1->seguent;
    n1->seguent = n2;
    n2->seguent = aux;  
    n1 = aux;
    --c.longitud;
  }
  if (c.longitud > 0) {
    n1->seguent = n2;
    ultim_node = c.ultim_node;   
  } 
  else ultim_node = n1;
  c.ultim_node = NULL;
}