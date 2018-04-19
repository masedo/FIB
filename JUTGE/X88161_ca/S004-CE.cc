#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef vector <vector<int> > Matriu;
typedef vector <vector<pair<int,int> > > Taula_resultats;

void llegir_taula_resultats (Taula_resultats& T, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> T[i][j].first;
      cin >> T[i][j].second;
    }
  }  
}

void fer_classificacio(Taula_resultats& T, Matriu& M, int n) {

  for (int i = 0; i < n; ++i) {
    M[i][j] = i+1;
    for (int j = 0; j < n; ++j) {
      
      if (i != j) {
	if (T[i][j].first > T[i][j].second) M[i][1] = M[i][1] + 3;
        else if (T[i][j].second > T[i][j].first) M[j][1] = M[j][1] + 3;
        else if (i != j) {
	  M[j][1] = M[j][1] + 1;
	  M[i][1] = M[i][1] + 1;
	}
        M[i][2] = M[i][2] + T[i][j].first;
        M[j][3] = M[j][3] + T[i][j].first;
      
        M[i][3] = M[i][3] + T[i][j].second;
        M[j][2] = M[j][2] + T[i][j].second;      
      }
    }
  }
}

bool comp (const vector<int>& a, const vector<int>& b) {
  if (a[1] == b[1] and (a[2]-a[3]) == (b[2]-b[3])) return a[0] < b[0];
  else if (a[1] == b[1]) return (a[2]-a[3]) > (b[2]-b[3]);
  else return a[1] > b[1];
}
 
void escriure_matriu (const Matriu& M) {
  int s1 = M.size(), s2 = M[0].size();
  for (int i = 0; i < s1; ++i) {
    for (int j = 0; j < s2; ++j) {
      cout << M[i][j];
      if (j < s2-1) cout << " ";
    }
    cout << endl;
  }  
}

int main() {
  int n;
  cin >> n;
  
  pair<int,int> A(0,0);
  Taula_resultats T(n, vector<pair<int,int> > (n,A));
  llegir_taula_resultats (T, n);
    
  Matriu C(n, vector<int> (4,0));
  fer_classificacio(T, C, n);
  
  sort (C.begin(), C.end(), comp);
  
  escriure_matriu(C);
}
  
  
  
  