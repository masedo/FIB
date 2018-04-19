#include <iostream>
using namespace std;


void write_binary(int n, int k) {
  int sol = 0;
  if ((n/2) < 2) {
    sol = 10*(n/2) + n%2;
    if (n/2 == 0) ++k;
    for (int i = 2; i < k; ++i) cout << 0;
  }
    
  else {
    --k;
    write_binary (n/2, k);
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