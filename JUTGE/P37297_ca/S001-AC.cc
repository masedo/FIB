#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a=0, r=0;
  while (a<3) {
    r=r+n%10;
    n=n/10;    
    ++a;
  }
  cout << r << endl;
}
  