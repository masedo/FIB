#include <iostream>
using namespace std;
int main() {
  int k, n, m;
  cin >> k >> n >> m;
  for (int a=0; a<k; ++a) {
    if (a>0) cout << endl;
    int s=9;
    for (int b=0; b<n; ++b) {
      for (int c=0; c<m; ++c) {
	cout << s;
	s=s-1;
	if (s<0) s=9;
      }
      cout << endl;
    }
  }
}