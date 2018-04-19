#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (esq <= dre) {
    
    int r = (esq + dre)/2;
    if (x <= v[r]) return posicio(x, v, esq, r-1);
    else return posicio(x, v, r+1, dre);
  }
  return -1;
}

int first_occurrence(double x, const vector<double>& v) {
  return posicio(x,v,0,v.size()-1);
}

int main() {}