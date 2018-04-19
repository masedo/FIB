#include <iostream>
#include <vector>
using namespace std;


typedef vector<char> vc;
typedef vector<vc> vvc;

int n,m;
vvc M;


int prof(int i, int j) {
  int k = 0;
  if (M[i][j] == 'X') return 0;
  if (M[i][j] == 't') {
    M[i][j] = '.';
    return 1 + prof(i+1,j) + prof(i-1,j) + prof(i,j+1) + prof(i,j-1);
  }
  M[i][j] = 'X';
  return prof(i+1,j) + prof(i-1,j) + prof(i,j+1) + prof(i,j-1);
}

int main() {
  cin >> n >> m;
  M = vvc(n+2, vc(m+2, 'X'));
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= m; ++j) 
      cin >> M[i][j];
       
  int i, j;
  cin >> i >> j;
  cout << prof(i,j)<< endl;
}