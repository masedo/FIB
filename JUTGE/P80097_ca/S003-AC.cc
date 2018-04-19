#include <iostream>
using namespace std;


//pinta _ _ _ _ _ ...n, coincideix amb el num de columnes
void pinta_barres_baixes_extrems(int n) {
  int cn = n;
  while (n > 0) {
    if (n == cn) cout << " _";
    else cout << "   _";
    --n;
  }
  cout << endl;
}

//pinta / \_/ \_ ...n, coincideix amb el num de columnes
void pinta_barres_inclinades_superiors(int n) {
  int cn = n;
  while (n > 0) {
    if (n == cn) cout << char(47) << " " << char(92);
    else cout << "_" << char(47) << " " << char(92);
    --n;
  }
  cout << endl;
}

//pinta \_/ \_/ ...n, coincideix amb el num de columnes
void pinta_barres_inclinades_inferiors(int n) {
  int cn = n;
  while (n > 0) {
    if (n != cn) cout << " ";
    cout << char(92) << "_" << char(47);
    --n;
  }
  cout << endl;
}

//pinta els ruscs
void pinta_rusc(int f, int c) {
  for (int i = 0; i < f; ++i) {
    if (i == 0) pinta_barres_baixes_extrems(c);
    pinta_barres_inclinades_superiors(c);
    pinta_barres_inclinades_inferiors(c);
  }
}

int main() {
  int a, b, i = 0;
  while (cin >> a >> b) {
    if (i > 0) cout << endl;
    pinta_rusc(a, b);
    ++i;
  }
}
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 
