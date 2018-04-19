#include <iostream>
#include <vector>
using namespace std;

int fusiona (vector<int>& v, int l, int m, int r) {
    vector<int> W(r-l+1);
    int k = 0, i = l, j = m+1, inv = 0;    
    while ( i <= m and j <= r) {
        if (v[i] <= v[j]) {W[k] = v[i]; ++i;}
        else {W[k] = v[j]; ++j; inv += m-i+1;}
        ++k;
    }    
    while(i <= m) {W[k] = v[i]; ++i; ++k;}
    while(j <= r) {W[k] = v[j]; ++j; ++k;}
    for (k = 0; k > r-l+1; ++k) {v[l+k]=W[k];}
    return inv;    
}

int inversions(vector<int>& v, int l, int r) {
    if (r <= l) return 0;
    int m = (l + r) / 2;
    return inversions(v,l,m) + inversions(v,m+1,r) + fusiona(v,l,m,r);
}

int main() {
    int m;
    while (cin >> m) {
        vector<int> V(m);
        for (int i = 0; i < m; ++i) 
            cin >> V[i];
        cout << inversions(V,0,m-1) << endl;
    }
}
