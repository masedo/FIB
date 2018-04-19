#include <stack>
#include <iostream>
using namespace std;


int main() {
  stack<char> P;
  char c;
  
  cin >> c;
  while (c != '.') {
    P.push(c);
    cin >> c;
  }
  
  int par = 0, cor = 0;
  bool b = true;
  while (not P.empty() and b) {
    bool c_tancat = false, p_tancat = false;
    
    if (P.top() == ']') {
      ++cor; c_tancat = true;
    }
    else if (P.top() == '[') --cor;
    else if (P.top() == ')') {
      ++par; p_tancat = true;
    }
    else --par;
    
    if (cor < 0 or par < 0) b = false;
    
    P.pop();
    
    if (not P.empty()) {
      if ((P.top() == '[' and p_tancat) or (P.top() == '(' and c_tancat))
	b = false;
    }
  }
  if (b) cout << "Correcte" << endl;
  else cout << "Incorrecte" << endl;
}
  
  
  
  
  
  
  
  
  