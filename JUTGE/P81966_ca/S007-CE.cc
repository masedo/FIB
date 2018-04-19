#include <iostream>
#include <vector>
using namespace std;


int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (x < v[esq] or x > v[dre] or esq > dre) return -1;
    
    else {
      int r = (esq + dre)/2;
      if (x < v[r]) return posicio(x, v, esq, r-1);
      else if (x > v[r]) return posicio(x, v, r+1, dre)
      else return r;
    }
}

int main() {}