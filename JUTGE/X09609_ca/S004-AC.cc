// #include <howarto>

#include "Arbre.hh"



static node_arbre* sub_arrel_imm(node_arbre* n, const T& x, int &dist) {
    node_arbre* p = NULL;

    if (n!= NULL) {
        if (n->info == x) {
            p = copia_node_arbre(n);
        }
        else {
            int dist1, dist2;
            dist1 = dist2 = dist + 1;
            p = sub_arrel_imm(n->segE, x, dist1);
            node_arbre* p_aux = NULL;
            p_aux = sub_arrel_imm(n->segD, x, dist2);
            if (p == NULL) {
                p = p_aux;
                dist = dist + dist2;
            }
            else if (p != NULL and p_aux != NULL) {
                if (dist1 > dist2) {
                    p = p_aux;
                    dist = dist + dist2;
                }
            }
            else dist = dist + dist1;
        }
    }

    return p;
}


/* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
    int dist = 0;
    asub.primer_node = sub_arrel_imm(this->primer_node, x, dist);
}