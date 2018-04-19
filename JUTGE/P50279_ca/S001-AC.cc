#include <iostream>
using namespace std;


char complement(char c) {
  if (c == 'A') return 'T';
  else if (c == 'T') return 'A';
  else if (c == 'C') return 'G';
  else return 'C';
}

int main() {
  char a, b, c;
  cin >> a >> b;
  while (cin >> c) {
    if (a == 'T' and b == 'A' and c == 'G') {
      while (cin >> c) cout << complement(c);
    }
    
    a = b;
    b = c;
  }
  cout << endl;
}