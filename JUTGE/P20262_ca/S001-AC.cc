#include <iostream>
using namespace std;


int main() {
  int n;
  
  while (cin >> n) {
    
    int suma = 0, max = 0, min = 0;
    for (int i = 0; i < n; ++i) {
      
      int c;
      cin >> c; 
      suma += c;
      if (suma > max) max = suma;
      if (suma < min) min = suma;
    }
    cout << max << " " << suma - min << endl;
  }
}
      

     
    
    
    