#include <vector>
#include <iostream>
#include <queue>
using namespace std;


typedef vector<vector<char>> VVC;
typedef vector<vector<bool>> VVB;

vector<int> di {0,1,0,1};
vector<int> dj {1,0,1,0};

int segona_dist_bfs(VVC &tauler, VVB &visitats, int x, int y) {
    queue<pair<int,int>> cua;
    cua.insert({x,y});
    int dist = 0;
    bool primer = true;
    while (not cua.empty()) {
        int a, b;
        a = cua.top().first();
        b = cua.top().second();
        cua.pop();
        if (tauler[a][b] != 'X') {
            for (int i = 0; i < 4; ++i) {
                int ii = a+di[i];
                int jj = b+dj[i];
                if (tauler[ii][jj] == t) {
                    if (primer) {
                        primer = false;
                        tauler[ii][jj] = '.';
                        cua.insert({ii,jj});
                    }
                    else return dist +1;
                }
                else if (tauler[ii][jj] == '.') {
                    cua.insert({ii,jj});
                }
            }
            ++dist;
        }
    }
}            

int main() {
    int n, m;
    cin >> n >> m;
    VVC tauler(n+2,vector<char>(m+2,'X'));
    VVB visitats(n+2,vector<bool>(m+2,false));
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) 
            cin >> VVC[i][j];
    int x, y;
    cin >> x >> y;
    int r = segona_dist_bfs(tauler,visitats,x,y);
    if (r == -1) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << r << endl;
}