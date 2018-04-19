#include <vector>
#include <iostream>
#include <queue>
using namespace std;


typedef vector<vector<char>> VVC;
typedef vector<vector<int>> VVI;

vector<int> di {0,1,0,-1};
vector<int> dj {1,0,-1,0};

int segona_dist_bfs(VVC &tauler, VVI &dist, int x, int y) {
    queue<pair<int,int>> cua;
    cua.push({x,y});
    dist[x][y] = 0;
    vector<int> ret;
    while (not cua.empty()) {
        int a, b;
        a = cua.front().first;
        b = cua.front().second;
        cua.pop();
        if (tauler[a][b] == 't') {
            ret.push_back(dist[a][b]);
        }                        
        for (int i = 0; i < 4; ++i) {
            int ii = a+di[i];
            int jj = b+dj[i];
            if (tauler[ii][jj] != 'X' and dist[ii][jj] == -1) {
                dist[ii][jj] = dist[a][b] +1;
                cua.push({ii,jj});
            }
        }
    }
    if (ret.size() < 2) return -1;
    else return ret[ret.size()-2];
    
}            

int main() {
    int n, m;
    cin >> n >> m;
    VVC tauler(n+2,vector<char>(m+2,'X'));
    VVI dist(n+2,vector<int>(m+2,-1));
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) 
            cin >> tauler[i][j];
    int x, y;
    cin >> x >> y;
    int r = segona_dist_bfs(tauler,dist,x,y);
    if (r == -1) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << r << endl;
}