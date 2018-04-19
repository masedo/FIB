#include <iostream>
#include <cmath>
using namespace std;


//transforma els símbols a binari
void llegeix_hora (int& h, int& m, int& s) {
  char c;
  int contb = 0, n;
  
  h = 0; m =0; s = 0;
  while (cin >> c) { 
    cin >> c;
    if (c == '*') n = 1;
    else n = 0;
    
    if (c == '|') ++contb; 
    else {
      
      //hores en binari
      if (contb == 1) {
	h = 10*h + n; 
      }
      
      //minuts en bianri
      else if (contb == 2) {
	m = 10*m + n;
      }
      
      //segons en binari
      else s = 10*s + n;
    }
  }
}

//escriu l'hora en binari a decimal
void escriu_hora (int h, int m, int s) {
  int h1 = 0, m1 = 0, s1 = 0, i = 0;
  
  while (h > 0) {
    h1 = h1 + pow((h/10), i);
    h = h/10;
    ++i;
  }
   i = 0;
   
  while (m > 0) {
    m1 = m1 + pow((m/10), i);
    m = m/10;
    ++i;
  }
  
  i = 0;
  while (s > 0) {
    s1 = s1 + pow((s/10), i);
    s = s/10;
    ++i;
  }
  
  cout << h1 << ":" << m1 << ":" << s1 << endl;
}

int main() {
  int n;
  for (int i = 0; i < n; ++i) {
    int h, m, s;
    llegeix_hora (h, m, s);
    escriu_hora (h, m, s);
  }
}
    
      
    
   
    