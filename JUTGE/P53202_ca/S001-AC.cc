#include <iostream>
using namespace std;

void escriu_binari (int n) {
  int sol = 0;
  if ((n/2) < 2) sol = 10*(n/2) + n%2;
  else {
    escriu_binari (n/2);
    sol = 10*sol + n%2;
  }
  cout << sol;
}

void nombre_en_azathoth (int n) {
  if ((n/50) < 50) {
    if (n >= 50) {
      cout << ".";
      escriu_binari(n/50);
    }
    cout << ".";
    escriu_binari(n%50);
    cout << ".";
  }
  else {
    nombre_en_azathoth(n/50);
    escriu_binari(n%50);
    cout << ".";
  }
}

int main() {
  int n;
  while (cin >> n) {
    cout << n << " = ";
    nombre_en_azathoth(n); 
    cout << endl;
  }
}
    
 
