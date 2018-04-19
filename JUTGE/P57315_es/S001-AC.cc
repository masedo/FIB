#include <iostream>
using namespace std;
int main() {
  int x, y, z;
  char w, s, t;
  cin >> x >> y >> z >> w >> s >> t;
  int max, min, med;
  if (x >= y) max = x;
   else max = y;
  if (z > max) max = z;
  if (x <= y) min = x;
    else min = y;
  if (z < min) min = z;
  if ((x < y and x > z) or (x < z and x > y)) med = x;
  if ((y < x and y > z) or (y < z and y > x)) med = y;
  if ((z < y and z > x) or (z < x and z > y)) med = z;
  if (w == 'A' and s == 'B') cout << min << ' ' << med << ' ' << max << endl;
  if (w == 'A' and s == 'C') cout << min << ' ' << max << ' ' << med << endl;
  if (w == 'B' and s == 'A') cout << med << ' ' << min << ' ' << max << endl;
  if (w == 'B' and s == 'C') cout << med << ' ' << max << ' ' << min << endl; 
  if (w == 'C' and s == 'A') cout << max << ' ' << min << ' ' << med << endl;
  if (w == 'C' and s == 'B') cout << max << ' ' << med << ' ' << min << endl;   
}
  
 