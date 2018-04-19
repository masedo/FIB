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

vector<int> di = {0, 1, 0,-1};
vector<int> dj = {1, 0,-1, 0};

int dist_min_bfs(int i, int j) {
  pair<int, int> P(i, j);
  no_visitats.push(P);  
  D[i][j] = 0;
  
  while(not no_visitats.empty()) {
    i = no_visitats.front().first;
    j = no_visitats.front().second;
    no_visitats.pop();

    for (int k = 0; k < 4; ++k) {
        int ii = i + di[k];
	int jj = j + dj[k];
	if (M[ii][jj] == 't') return D[i][j]+1;
	else if (M[ii][jj] == '.' and D[ii][jj] == -1) {
	  D[ii][jj] = D[i][j]+1;
	  no_visitats.push({ii, jj});
        }
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