#include <iostream>
using namespace std;


int main() {
  int n;
  while (cin >> n) {
    
    int a, b;
    cin >> a;
    
    int sol=0;
    for (int i=0; i < n-1; ++i) {
      cin >> b;
      if (b%2==0) sol = sol + a;
      a=b;
    }
    cout << sol << endl;
  }
}
     