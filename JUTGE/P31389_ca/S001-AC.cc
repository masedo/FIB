#include <vector>
#include <iostream>
using namespace std;


void escriure(vector<int> &v, int c) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < c; ++j) {
            if (v[i] == j) cout << 'R';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}
        
void torres(int k, int f, int c, vector<int> &files, vector<bool> &marcat) {
    if (k == f) escriure(files, c);
    else {
        for (int i = 0; i < c; ++i) {
            if (not marcat[i]) {
                marcat[i] = true;
                files[k] = i;
                torres(k+1,f,c,files,marcat);
                marcat[i] = false;
            }
        }
    }
}    

int main() {
    int f, c;
    cin >> f >> c;
    vector<int> files(f);
    vector<bool> marcat(c,false);
    torres(0,f,c,files,marcat);
}