#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<double, int> ArcP; // arc amb pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

void dijkstra(const GrafP& G, int s, vector<int>& d,vector<int>& p) {
    int n = G.size();
    d = vector<int>(n, 1000000000); d[s] = 0;
    p = vector<int>(n, -1);
    vector<bool> S(n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
    Q.push(ArcP(0, s));
    while (not Q.empty()) {
        int u = Q.top().second; Q.pop();
        if (not S[u]) {
            S[u] = true;
            for (int i = 0; i < int(G[u].size()); ++i) {
                int v = G[u][i].second;
                int c = G[u][i].first;
                if (d[v] > d[u] + c) {
                    d[v] = d[u] + c;
                    p[v] = u;
                    Q.push(ArcP(d[v], v));
                }             
            }            
        }        
    }     
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        GrafP G(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back(ArcP(c,v));
        }
        int x, y;
        cin >> x >> y;
        vector<int> d, p;
        dijkstra(G,x,d,p);
        if (p[y] != -1) 
            cout << d[y] << endl;        
        else cout << "no path from " << x << " to " << y << endl;         
    }
}