#include <vector>
#include <iostream>
using namespace std;

typedef vector<vector<char>> matriu;

vector<bool> usats;
matriu M;

void print_matrix(const matriu &m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            if (j > 0) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
}

bool repetit(int i, int j, int k) {
    bool trobat = false;
    for (int x = 0; x < 9 and not trobat; ++x) {
        if (M[i][x] != '.') {
            trobat = int(M[i][x]-'0') == k;
        }
    }
    for (int x = 0; x < 9 and not trobat; ++x) {
        if (M[i][x] != '.') {
            trobat = int(M[x][j]-'0') == k;
        }
    }
    for (int x = (i/3)*3; x < ((i/3)*3)+2; ++x) {
        for (int y = (j/3)*3; y < ((j/3)*3)+2; ++y) {
            trobat = int(M[x][y]-'0') == k;
        }
    }    
	return trobat;
}

bool solve(int i, int j) {
    if (i == 8 and j == 8) {
        print_matrix(M);
        return true;
    }
    if (M[i][j] == '.') {
        for (int x = 1; x < 10; ++x) {        
            if (not repetit(i,j,x)) {
                M[i][j] = x+'0';
                ++j;
                if (j == 9) {j = 0; ++i;}
                if (solve(i,j)) return true;
            }            
        }    
    }
    else {
        ++j;
        if (j == 9) {j = 0; ++i;}
        solve(i, j);
    }
}
            

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << endl;
        M = matriu(9,vector<char>(9));
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                cin >> M[j][k];
            }
        }
        solve(0,0);
    }
}
    
    