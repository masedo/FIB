#include <iostream>
#include <vector>
using namespace std;

void leer(vector< vector<int> >& v) {
  int n = v.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> v[i][j];
}

bool okFila(int i, const vector< vector<int> >& t, int sum) {
  int s = 0;
  for (int j = 0; j < t.size(); ++j)
    s += t[i][j];
  return s == sum;
}

bool okCol(int j, const vector< vector<int> >& t, int sum) {
  int s = 0;
  for (int i = 0; i < t.size(); ++i)
    s += t[i][j];
  return s == sum;

}

bool okDiag1(const vector< vector<int> >& t, int sum) {
  int s = 0;
  for (int k = 0; k < t.size(); ++k) //diagonal SE: fila = col
    s += t[k][k];
  return s == sum;
}

bool okDiag2(const vector< vector<int> >& t, int sum) {
  int n = t.size();
  int s = 0;
  for (int k = 0; k < n; ++k) //diagonal SO: fila+col = n-1
    s += t[k][n-1-k];
  return s == sum;
}

bool estanTodos(const vector< vector<int> >& t) {
  int n = t.size();
  vector<bool> esta(n*n+1, false);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (t[i][j] < 1 or t[i][j] > n*n) return false;
      else esta[t[i][j]] = true;
    }
  for (int i = 1; i <= n*n; ++i)
      if (not esta[i]) return false;
  return true;
}

bool quadrat_magic(const vector< vector<int> >& t) {
  int n = t.size();
  if (not estanTodos(t)) return false;
  int sum = 0;
  for (int j = 0; j < n; ++j) // sum = suma de la primera fila
    sum += t[0][j];
  for (int i = 1; i < n; ++i) 
    if (not okFila(i, t, sum)) return false;
  for (int j = 0; j < n; ++j)
    if (not okCol(j, t, sum)) return false;
  if (not okDiag1(t, sum)) return false;
  if (not okDiag2(t, sum)) return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  vector< vector<int> > v(n, vector<int>(n));
  leer(v);
  if (quadrat_magic(v)) cout << "es magic" << endl;
  else cout << "no es magic" << endl;
}