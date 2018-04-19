#include <iostream>
using namespace std;
int main() {
  char x, y;
  cin >> x >> y;
  if ((x == 65 and y == 65) or (x == 80 and y == 80) or (x == 86 and y == 86)) cout << "-" << endl;
  if ((x == 65 and y == 80) or (x == 80 and y == 86) or (x == 86 and y == 65)) cout << "1" << endl;
  if ((x == 80 and y == 65) or (x == 86 and y == 80) or (x == 65 and y == 86)) cout << "2" << endl;
}