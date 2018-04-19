#include <iostream>
using namespace std;
int main() {
  char a;
  cin >> a;
  if ((a<='z' and a>='a') or (a<='Z' and a>='A')) cout << "lletra" << endl;
  else if (a<='9' and a>='0') cout << "digit" << endl;
  else cout << "res" << endl;
}