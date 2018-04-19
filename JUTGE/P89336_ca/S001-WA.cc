#include <iostream>
#include <string>
using namespace std;


void girar_llista_paraules () {
  string a;
  int cont = 0;
  if (cin >> a) {
    ++cont;
    girar_llista_paraules ();
  }
  if (cont > 0) {
    cout << a << endl;
    cont = cont/2;
  }
}

int main() {
  girar_llista_paraules();
}