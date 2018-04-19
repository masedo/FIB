#include <iostream>
#include <cmath>
using namespace std;


//transforma els símbols a binari
void llegeix_hora (int& h, int& m, int& s) {
  char c;
  h = 0; m =0; s = 0;
  
  int contb = 0, n;
  cin >> c;  
  while (contb < 3) {    
    cin >> c;
    
    int sol = 0;
    while (c != '|') {
      if (c == '*') n = 1;
      else n = 0;
      sol = 10*sol + n;
      cin >> c;
    }
    if (contb == 0) h = sol;
    else if (contb == 1) m = sol;
    else s = sol;
    if (c == '|') ++contb;
  }
}

//escriu l'hora en binari a decimal
void escriu_hora (int h, int m, int s) {
  int h1 = 0, m1 = 0, s1 = 0, i = 0;
  
  while (h > 0) {
    h1 = h1 + ((h%10)*pow(2, i));
    h = h/10;
    ++i;
  }
   i = 0;
   
  while (m > 0) {
    m1 = m1 + (m%10)*pow(2, i);
    m = m/10;
    ++i;
  }
  
  i = 0;
  while (s > 0) {
    s1 = s1 + (s%10)*pow(2, i);
    s = s/10;
    ++i;
  }
  
  cout << h1 << ":" << m1 << ":" << s1 << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int h, m, s;
    llegeix_hora (h, m, s);
    escriu_hora (h, m, s);
  }
}
    
      
    
   
    