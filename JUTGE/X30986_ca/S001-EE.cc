#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct Paraula {
  int num;
  string lletres;
};

bool comp (const Paraula& a, const Paraula& b) {
  if (a.num == b.num) return a.lletres < b.lletres;
  else return a.num > b.num;
}

int main() {
  int n;
  while (cin >> n) {
    vector<Paraula> paraules(0);
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      bool trobat = false;
      for (int j = 0; j < paraules.size(); ++j) {
	if (paraules[j].lletres == s) {
	  ++paraules[j].num;
	  trobat = true;
	}
      }
      if (not trobat) {
	Paraula p;
	paraules.push_back(p);
	paraules[paraules.size() -1].lletres = s;
	paraules[paraules.size() -1].num = 1;
      }
    }
    
    sort(paraules.begin(), paraules.end(), comp);
    for (int i = 0; i < paraules.size(); ++i) {
      cout << paraules[i].num << " " << paraules[i].lletres << endl;
    }
    cout << "----------" << endl;
  }
}
    
      
      