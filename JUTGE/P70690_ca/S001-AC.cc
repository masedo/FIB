#include <iostream>
#include <vector>
using namespace std;


typedef vector<char> vc;
typedef vector<vc> vvc;

int n,m;
vvc M;


bool prof(int i, int j) {
  if (M[i][j] == 'X') return false;
  if (M[i][j] == 't') return true;
  M[i][j] = 'X';
  return prof(i+1,j) or prof(i-1,j) or prof(i,j+1) or prof(i,j-1);
}

int main() {
  cin >> n >> m;
  M = vvc(n+2, vc(m+2, 'X'));
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= m; ++j) 
      cin >> M[i][j];
       
  int i, j;
  cin >> i >> j;
  cout << (prof(i,j) ? "yes" : "no") << endl;
}