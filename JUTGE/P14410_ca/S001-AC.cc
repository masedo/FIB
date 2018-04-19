#include <iostream>
using namespace std;


void convergeix(int n, int& k, int& lluny) {
  k = 0;
  lluny = n;
  
  while (n > 1) {
    ++k;
    
    if (n%2 == 0) n = n/2;
    else n = n*3 + 1;
    
    if (n > lluny) lluny = n;
  }
}

int main() {
  int n, k, k1, lluny;
  cin >> n >> k;
  convergeix (n, k1, lluny);
  int k2, lluny2, max = 0;
  for (int i = 1; i <= n; ++i) {
    convergeix (i, k2, lluny2);
    if (lluny2 > max) max = lluny2;
    if (k2 >= k) cout << i << endl;
  }
  cout << "S'arriba a " << max << "." << endl;
}
  
  