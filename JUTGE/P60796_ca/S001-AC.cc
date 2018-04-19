#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<char> vc;
typedef vector<int> ve;
typedef vector<vc> vvc;
typedef vector<ve> vve;

queue<pair<int, int> > no_visitats;
vvc M;
vve D;

int dist_min_bfs(int i, int j) {
  pair<int, int> P(i, j);
  no_visitats.push(P);  
  D[i][j] = 0;
  
  while(not no_visitats.empty()) {
    i = no_visitats.front().first;
    j = no_visitats.front().second;
    no_visitats.pop();
        
    //dreta
    if (M[i][j+1] == 't') return D[i][j]+1;
    else if (M[i][j+1] == '.' and D[i][j+1] == -1) {
      D[i][j+1] = D[i][j]+1;
      pair<int, int> P(i, j+1);
      no_visitats.push(P);
    }
    //esquerra
    if (M[i][j-1] == 't') return D[i][j]+1;
    else if (M[i][j-1] == '.' and D[i][j-1] == -1) {
      D[i][j-1] = D[i][j]+1;
      pair<int, int> P(i, j-1);
      no_visitats.push(P);
    }
    //dalt
    if (M[i-1][j] == 't') return D[i][j]+1;
    else if (M[i-1][j] == '.' and D[i-1][j] == -1) {
      D[i-1][j] = D[i][j]+1;
      pair<int, int> P(i-1, j);
      no_visitats.push(P);
    }
    //baix
    if (M[i+1][j] == 't') return D[i][j]+1;
    else if (M[i+1][j] == '.' and D[i+1][j] == -1) {
      D[i+1][j] = D[i][j]+1;
      pair<int, int> P(i+1, j);
      no_visitats.push(P);
    }      
  }
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  M = vvc(n+2, vc(m+2, 'X'));
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= m; ++j) 
      cin >> M[i][j];
       
  int i, j;
  cin >> i >> j;  
  D = vve(n+2, ve(m+2, -1));
  int dist = dist_min_bfs(i,j);
  if (dist != -1) cout << "distancia minima: " << dist << endl;
  else cout << "no es pot arribar a cap tresor" << endl;
}