// #include <howarto>
#include "ArbreG.hh"

static T max_suma_cami_imm(node_arbreGen* n, bool &valido) {
    T suma;
    if(n!=NULL) {
        valido = true;
        suma = n->info;
        bool primer = true;
        T max;
        for (int i = 0; i < n->seg.size(); ++i) {
            bool b = false;
            T aux = max_suma_cami_imm(n->seg[i], b);
            if (b) {
                if (primer) {
                    primer = false;
                    max = aux;
                }
                else if (max < aux) {
                    max = aux;
                }
            }
        }
        if (n->seg.size() > 0) suma += max;

    }
    return suma;
}

/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
T max_suma_cami() const {
    bool valido = false;
    return max_suma_cami_imm(this->primer_node, valido);
}