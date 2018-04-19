#include <vector>
using namespace std;


bool i_resistant_search(double x, const vector<double> &v, int l, int r) {
    if (l > r) return false;
    if (l == r) return v[l] == x;
    if(l + 1 == r) return v[l] == x or v[r] == x;
    int m = (l+r) / 2;
    if (v[m] > x) return v[m+1] == x or i_resistant_search(x,v,l,m-1);
    else if (v[m] < x) return v[m-1] == x or i_resistant_search(x,v,m+1,r);
    else return true;
}

bool resistant_search(double x, const vector<double>& v) {
    return i_resistant_search(x, v, 0, v.size()-1);
}

int main() {}