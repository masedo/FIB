#include <iostream>
#include <queue>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

int main() {
  int n,m;
  while (cin >> n >> m) {
    VVE G(n);
    VE grau(n,0);
    while (m --) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      ++grau[y];
    }
    
    priority_queue<int> Q;
    for (int x = 0; x < n; ++x)
      if (grau[x] == 0) Q.push(-x);//guardem els numeros negatius per agafar el mes petit a dalt de tot
    
    bool primer = true;  
    while (not Q.empty()) {
      int x = -Q.top(); Q.pop();
      if (primer) primer = false;
      else cout << ' ';
      cout << x;
      for (int i = 0; i < (int)G[x].size(); ++i) { //->
	int y = G[x][i];			   //for (int y : G[x]
	if (--grau[y] == 0) Q.push(-y);
      }
    }
  }
}