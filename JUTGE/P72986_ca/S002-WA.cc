#include <iostream>
using namespace std;
int main() {
  cout.setf(ios::fixed);
  cout.precision(4);
  double x;
  cin >> x;
  double c, d=0;
  while (cin >> c) {
    d = (d+c)*x;
  }
  if (d==0) cout << x << endl;
  else cout << d/x << endl;
}
    
   
  