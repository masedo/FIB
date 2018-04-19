#include <iostream>
#include <vector>
using namespace std;


int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (x < v[esq] or x > v[dre] or esq > dre) return -1;
        
    int r = (esq + dre)/2;
    if (v[r] == x) return r;
    
    if (x < v[r]) return posicio (x, v, esq, r-1);
    return posicio (x, v, r+1, dre);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> v(n);
        for (int i = 0; i < n; ++i) {
            double x;
            cin >> x;
            v[i] = x;
        }
        int a, b, c;
        cin >> a >> b >> c;
        cout << posicio(a, v, b, c) << endl;
    }
}
   