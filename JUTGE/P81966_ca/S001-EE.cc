#include <iostream>
#include <vector>
using namespace std;


int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (x < v[esq] or x > v[dre] or esq > dre) return -1;
    
    int r = (esq + dre)/2;
    if (v[r] == x) return r;
    
    if (x < r) return posicio (x, v, esq, r);
    return posicio (x, v, r, dre);
}

int main() {}
   