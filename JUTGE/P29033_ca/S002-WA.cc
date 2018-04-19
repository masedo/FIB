#include <iostream>
#include <vector>
#include <map>
using namespace std;



int main() {
    int v, a;
    while (cin >> v >> a) {
        vector<vector<int> > adj(v);
        map<int, char> colors;
        int x, y;
        for (int i = 0; i < a; ++i) {            
            cin >> x >> y;
            adj[x].push_back(y);
         
        }
        bool trobat = false;
        for (int i = 0; i < x and not trobat and a != 0; ++i) {
            pair<map<int,char>::iterator,bool> ret;
            if (i%2 == 0) {
                ret = colors.insert(pair<int,char>(i,'B'));
                if (ret.second == false and ret.first->second == 'W') trobat = true;
                for (int j = 0; j < adj[i].size() and not trobat; ++j) {
                    ret = colors.insert(pair<int,char>(adj[i][j],'B'));
                    if (ret.second == false and ret.first->second == 'W') trobat = true;        
                }
            }
            else {
                ret = colors.insert(pair<int,char>(i,'W'));
                if (ret.second == false and ret.first->second == 'B') trobat = true;
                for (int j = 0; j < adj[i].size() and not trobat; ++j) {
                    ret = colors.insert(pair<int,char>(adj[i][j],'W'));
                    if (ret.second == false and ret.first->second == 'B') trobat = true;        
                }
            }            
        }
        if (trobat) cout << "no" << endl;
        else cout << "yes" << endl;
    }  
}
