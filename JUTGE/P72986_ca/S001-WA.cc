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
  cout << d/x << endl;
}
    
   
  