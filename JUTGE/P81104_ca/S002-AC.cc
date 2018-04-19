#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Assignatura {
  string nom;
  double nota;
};

struct Alumne {
  string nom;
  int dni;
  vector<Assignatura> ass;
};

double nota(const vector<Alumne>& alums, int dni, string nom) {
  int s = alums.size();
  for (int i = 0; i < s; ++i) {
    if (alums[i].dni == dni) {
      int s1 = alums[i].ass.size();
      for (int j = 0; j < s1; ++j) {
	if (alums[i].ass[j].nom == nom) return alums[i].ass[j].nota;
      }
    }
  }
  return -1;
}

double mitjana(const vector<Assignatura>& ass) {
  int s = ass.size();
  double suma = 0, cont = 0;
  bool algun = false;
  for (int i = 0; i < s; ++i) {
    if (ass[i].nota > -1) {
      algun = true;
      ++cont;
      suma = suma + ass[i].nota;
    }
  }
  if (not algun) return -1;
  else return suma/cont;
}

void compta(const vector<Alumne>& alums, int dni, string nom, int& com) {
  double N = nota(alums, dni, nom);
  
  com = 0;
  int s = alums.size();
  for (int i = 0; i < s; ++i)
    if (mitjana(alums[i].ass) > N) ++com;
}

void llegeix_dades(vector<Alumne>& v, int n) {
  for (int i = 0; i < n; ++i) {
    string s; cin >> s; v[i].nom = s;
    int dni; cin >> dni; v[i].dni = dni;
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      Assignatura A;
      string r; cin >> r; A.nom = r;
      double y; cin >> y; A.nota = y;
      v[i].ass.push_back(A);
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<Alumne> V(n);
  llegeix_dades(V, n);
  
  int dni;
  while (cin >> dni) {
    string A;
    cin >> A;
    int k;
    compta(V, dni, A, k);
    cout << k << endl;
  }
}
  
    
  
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  