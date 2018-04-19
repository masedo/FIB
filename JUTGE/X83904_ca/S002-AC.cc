#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;


void llegir_set_string(set<string> &S) {
  string s;
  cin >> s;
  while (s[0] != '.') {
    S.insert(s);
    cin >> s;
  }
}

void esc_set_string(const set<string> &s) {
  set<string>::const_iterator it = s.begin();
  while (it != s.end()) {
    cout << " " << *it;
    ++it;
  }
}

void calcular_tot_cap(const set<string> &al, const vector<set<string> > &act,
		      set<string> &tot, set<string> &cap) {
  set<string>::const_iterator it_al = al.begin();
  int n = act.size();
  vector<set<string>::const_iterator > it_act(n);
  for (int i = 0; i < n; ++i) it_act[i] = act[i].begin();
  
  while (it_al != al.end()) {
    bool totes = true, c = true;
    for (int i = 0; i < n; ++i) {
      if (it_act[i] != act[i].end() and *it_act[i] == *it_al) {
	++it_act[i];
	c = false;
      }
      else totes = false;
    }   
    
    if (totes) tot.insert(tot.end(),*it_al);
    if (c) cap.insert(cap.end(),*it_al);
    ++it_al;
  }
}

int main() {
  set<string> alumnes;
  llegir_set_string(alumnes);
  
  int n; 
  cin >> n;  
  vector<set<string> > activitats(n);
  for (int i = 0; i < n; ++i) llegir_set_string(activitats[i]);
  
  set<string> totes, cap;
  calcular_tot_cap(alumnes,activitats,totes,cap);
  cout << "Totes les activitats:";
  esc_set_string(totes);
  cout << endl << "Cap activitat:";
  esc_set_string(cap);
  cout << endl;
}