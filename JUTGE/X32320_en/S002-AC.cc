#include <iostream>
using namespace std;


bool is_circular_increasing() {
  bool trobat = false, segon = false;
  int a, b, i = 0;
  
  cin >> a;
  int min1 = a, max2 = 0;
  while (cin >> b and not trobat) {
    if (b < a) {
      ++i;
      segon = true;
    }
    
    if (not segon and b < min1) min1 = b;
    
    if (segon and b > max2) max2 = b;
    
    if (i > 1 or max2 > min1) trobat = true;
    a = b;
  }
  if (trobat) return false;
  return true;
}

int main() {
  if (is_circular_increasing()) cout << "yes" << endl;
  else cout << "no" << endl;
}