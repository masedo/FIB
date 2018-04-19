#include <iostream>
using namespace std;

void write_binary (int n, int k) {
  int sol = 0, cont = 2;
  if ((n/2) < 2) {
    if ((n/2) == 0 and n!= 0 and n!= 1) cout << 0;
    sol = 10*sol + 10*(n/2) + n%2;
    while (cont < k) {
      ++cont;
      cout << 0;
    }
  }
  
  else {
    ++cont;
    write_binary (n/2, k-1);
    sol = 10*sol + n%2;
  }
  cout << sol;  
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    write_binary (n, k);
    cout << endl;
  }
}