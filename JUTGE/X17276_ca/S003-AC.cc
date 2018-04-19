#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vi;
typedef vector< vector<int> > Mi;

bool dentro(int f, int c, int df, int dc, int nf, int nc) {
  return not (f+df >= nf or f+df < 0 or c+dc >= nc or c+dc < 0);
}

bool crec(int f, int c, int df, int dc, const Mi& m) {
  int nf = m.size();
  int nc = m[0].size();
  while (dentro(f,c,df,dc,nf,nc)) {
    if (m[f][c] >= m[f+df][c+dc]) return false;
    else {
      f += df;
      c += dc;
    }
  }
  return true;
}

void caso(int nf, int nc, const Mi& DIR) {
  Mi m(nf,Vi(nc));
  for (int i = 0; i < nf; ++i) {
    for (int j = 0; j < nc; ++j) cin >> m[i][j];
  }
  int f, c;
  cin >> f >> c;
  bool r = true;
  for (int i = 0; r and i < DIR.size(); ++i) {
    if (not crec(f,c,DIR[i][0],DIR[i][1],m)) r = false;
  }
  if (r) cout << "si";
  else cout << "no";
  cout << endl;
}

int main() {
  Mi DIR(4,Vi(2));
  
  DIR[0][0] = -1; DIR[0][1] = 1;
  DIR[1][0] = 1;  DIR[1][1] = 1;
  DIR[2][0] = -1; DIR[2][1] = -1;
  DIR[3][0] = 1;  DIR[3][1] = -1;
  int nf, nc;
  while (cin >> nf >> nc) caso(nf,nc,DIR);
}