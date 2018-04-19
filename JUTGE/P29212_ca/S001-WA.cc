#include <iostream>
using namespace std;


double potencia (double x, int n) {
  if (n == 0) {
      return 1;
  } 	
  else {
    double y = potencia (x, n / 2);
    if (n % 2 == 0) return y * y;
    else return y * y * x;
    } 
}

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    cout << int(potencia(a,b))%c << endl;
  }
}
