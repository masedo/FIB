#include <iostream>
using namespace std;


void escriu_triangle (int t) {
  int numespais = 2*t - 1, triangles = 0;
  for (int files = 0; files < 2*t; ++files) {
    for (int espais = 0; espais < numespais; ++espais) cout << " ";
    --numespais;
    
    if (files%2 == 0) {
      ++ triangles; 
      for (int triangle = 0; triangle < triangles; ++triangle) {
	cout << char(47) << char(92);
	if (triangles > 1 and triangle < t) cout << "  ";
      }
    }
    
    else {
      for (int triangle = 0; triangle < triangles; ++triangle) {
	cout << char(47) << "__" << char(92);
      }
    }
    
    
    cout << endl;
  }
}

int main() {
  int n, i = 0;
  cin >> n;
  while (n != 0 and n > 0) {
    if (i > 0) cout << endl;
    escriu_triangle (n);
    cin >> n;
    ++i;
  }
}
  
      
  