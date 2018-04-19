#include <iostream>
using namespace std;


int potencia_mod(int x, int n, int m) {
  if (n == 0) {
      return 1;
  } 	
  else {
    int mx = x%m;
    int y = potencia_mod(mx, n/2, m);
    if (n % 2 == 0) return (y*y)%m;
    else return (((y*y)%m)*x)%m;
    } 
}

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    
    cout << potencia_mod(a,b,c) << endl;
  }
}
