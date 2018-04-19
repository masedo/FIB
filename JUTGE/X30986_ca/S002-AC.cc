#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


struct Paraula {
  int num;
  string lletres;
};

bool comp (const Paraula& a, const Paraula& b) {
  if (a.num == b.num) return a.lletres < b.lletres;
  else return a.num > b.num;
};

int main() {
  int n;
  while (cin >> n) {
    vector <string> P(n);
    for (int i = 0; i < n; ++i) {
      cin >> P[i];
    }
    sort (P.begin(), P.end());
    
    vector <Paraula> W;
    int j = 0;
    bool primer_p = false;
    for (int i = 0; i < n; ++i) {
      if (primer_p and P[i] == W[j].lletres) ++W[j].num;
      else {
	if (primer_p) ++j;
	primer_p = true;
	Paraula par;
	par.num = 1;
	par.lletres = P[i];
	W.push_back(par);
      }
    }
    
    sort (W.begin(), W.end(), comp);
    
    int s = W.size();
    for (int i = 0; i < s; ++i) {
      cout << W[i].num << " " << W[i].lletres << endl;
    }
    cout << "----------" << endl;
  }
}
    
    