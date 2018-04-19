void concat(Cua &c) {
/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */

  if (primer_node == NULL) {
    primer_node = c.primer_node;
    ultim_node = c.ultim_node;
    longitud = c.longitud;
    c.longitud = 0;
  }
  else {
    if (c.ultim_node != NULL) {
      ultim_node->seguent = c.primer_node;
      ultim_node = c.ultim_node;
      longitud += c.longitud;
      c.longitud = 0;
    }
  }
}