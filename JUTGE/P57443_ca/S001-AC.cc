#include <iostream>
#include <vector>
using namespace std;


int main() {
  char c;
  while (cin >> c) {
    vector<char> v(12);
    v[0] = c;
    for (int i = 1; i < 12; ++i) {
      cin >> c;
      v[i] = c;
    }
    
    int suma = 0;
    int i = 11;
    while (i >= 0) {
      suma = suma + 3*(v[i]-'0');
      --i;
      suma = suma + (v[i]-'0');
      --i;
    }
    int desena_sup = ((suma/10)+1)*10;
    int desena_igual = (suma/10)*10;
    
    if (suma == desena_igual) v.push_back('0');
    else {
      c = '0' + (desena_sup-suma);
      v.push_back(c);
    }
   
    for (int j = 0; j < 13; ++j) cout << v[j];
    cout << endl;      
  }
}
     
      
    

    
  
    
  