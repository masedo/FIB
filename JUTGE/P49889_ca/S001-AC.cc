#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;
typedef vector<bool> VB;
typedef vector<char> VC;

int n;
VB usat1, usat2;
VC cons, voc, par;
    
void f(int i);

void g(int i) {
    if (i == (2*n)-1) {
        bool trobat = false;
        for (int j = 0; j < n and not trobat; ++j) 
            if (not usat2[j]) {
                par[i] = voc[j];  
                trobat = true;
            }
        for (int j = 0; j < 2*n; ++j)            
            cout << par[j];
        cout << endl;
        return;
    } 
    for (int j = 0; j < n; ++j) {
        if (not usat2[j]) {
            usat2[j] = true;
            par[i] = voc[j];
            f(i+1);
            usat2[j] = false;
        }
    }
}    

void f(int i) {     
    for (int j = 0; j < n; ++j) {
        if (not usat1[j]) {  
            usat1[j] = true;
            par[i] = cons[j];
            g(i+1);
            usat1[j] = false;
        }
    }
}

int main() {
  cin >> n;
  usat1 = VB(n,false);
  usat2 = VB(n,false);
  cons = VC(n);
  voc = VC(n);
  par = VC(2*n);
  for (int i = 0; i < n ; ++i) cin >> cons[i];
  for (int i = 0; i < n ; ++i) cin >> voc[i];
  f(0);
}