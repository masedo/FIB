#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ArcP; // arc amb pes
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

void dijkstra(const GrafP& G, int s, vector<int>& d,vector<int>& p, vector<int>& pas) {
    int n = G.size();
    d = vector<int>(n, 1000000000); d[s] = 0;
    p = vector<int>(n, -1);
    pas = vector<int>(n,0);
    pas[s] = 0;
    p[s] = s;
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
                    pas[v] = pas[u]+1;
                    Q.push(ArcP(d[v], v));
                }  
                else if (d[v] == d[u] + c and pas[v] > pas[u]+1) {
                    d[v] = d[u] + c;
                    p[v] = u;
                    pas[v] = pas[u]+1;
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
        vector<int> d, p, pas;
        dijkstra(G,x,d,p,pas);
        if (p[y] != -1) 
            cout << "cost " << d[y] << ", " << pas[y] << " step(s)" << endl;        
        else cout << "no path from " << x << " to " << y << endl;         
    }
}