#include <vector>

using namespace std;


int solitaris(const vector<int> &v) {
  int sol = 0, n = v.size();
  if (n == 1) ++sol;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      if (i < n-1 and v[i] != v[i+1]) ++sol;
    }
    else if (i == n-1) {
      if (i > 0 and v[i] != v[i-1]) ++sol;    
    }
    else if (v[i-1] != v[i] and v[i] != v[i+1]) ++sol;
  }
  return sol;
}
    

  