#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int r = (2*n)-1, q=0;
    for (int i=0; i < (2*n)-1; ++i) {
      int e=0;
      while (e < q) {
	cout << " ";
	++e;
      }
      int x=0;
      while (x < r) {
	cout << "X";
	++x;
      }
      cout << endl;
      
      if (i > n-2) {
	r = r+2;
	--q;
      }
      if (i < n-1) {
	r= r-2;
	++q;
      }
    }
    cout << endl << endl;
  }
}