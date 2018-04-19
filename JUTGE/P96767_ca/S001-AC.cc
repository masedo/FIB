#include <iostream>
#include <cmath>
using namespace std;
int main() {
  cout.setf(ios::fixed);
  cout.precision(4);
  double x, c, count=0;
  int a=0;
  cin >> x;
  while (cin >> c) {
    double s=0;
    s=c*(pow(x,a));
    ++a; 
    count = count + s;
  }
  cout << count << endl;
}
      