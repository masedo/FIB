#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n;

typedef pair<int,int> P;
// El graf (connex) esta representat amb llistes d’adjacencia
// Els parells son (cost, vertex)
int mst(const vector<vector<P>>& g) { // Retorna cost d’un MST
    vector<bool> vis(n, false);
    vis[0] = true;
    priority_queue<P, vector<P>, greater<P> > pq;
    for (P x : g[0]) pq.push(x);
    int sz = 1;
    int sum = 0;
    while (sz < n) {
        int c = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (not vis[x]) {
            vis[x] = true;
            for (P y : g[x]) pq.push(y);
            sum += c;
            ++sz; 
        } 
    }
    return sum; 
}

int main() {
    int a;
    while (cin >> n >> a) {
        vector<vector<P>> g(n);
        int u, v, w;
        for (int i = 0; i < a; ++i) {
            cin >> u >> v >> w;
            g[u-1].push_back({w,v-1});
            g[v-1].push_back({w,u-1});
        }
        cout << mst(g) << endl;
    }
}
        
        
        