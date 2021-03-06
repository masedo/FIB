#include <iostream>
#include <vector>
using namespace std;


void separar(vector<char> &v, vector<char> &e, char &op, vector<char> &d) {
  int par = 1;
  if (v[1] != '(') {
    e.push_back(v[1]);
    op = v[2];
    if (v[3] != '(') d.push_back(v[3]);
    else {
      int i = 3;
      while (par != 0) {
	d.push_back(v[i]);
	++i;
	if (v[i] == ')') --par;
      }     
    }
  }
  else {
    ++par;
    int i = 1;
    while (par != 1) {
      e.push_back(v[i]);
      ++i;
      if (v[i] == ')') --par;
    }
    op = v[i+1];
    i = i+2;
    if (v[i] != '(') d.push_back(v[i]);
    else {
      while (par != 0) {
	d.push_back(v[i]);
	++i;
	if (v[i] == ')') --par;
      } 
    }
  } 
}

int resultat_operacio(vector<char> &v) {
 if (v.size() == 1) return int(v[0]-'0');
 else {
   vector<char> esq, drt;
   char op;   
   separar(v,esq,op,drt);
   if (op == '+') {
     return resultat_operacio(esq) + resultat_operacio(drt);
   }
   else if (op == '-') {
     return resultat_operacio(esq) - resultat_operacio(drt);
   }
   else return resultat_operacio(esq) * resultat_operacio(drt);
 }
}

int main() {
  char c;
  vector<char> v;
  while (cin >> c) v.push_back(c);
  cout << resultat_operacio(v) << endl;
}
    