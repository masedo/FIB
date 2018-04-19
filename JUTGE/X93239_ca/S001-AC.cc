#include <vector>
using namespace std;


int suma_el(const vector<int> &v) {
  int suma = 0, n = v.size();
  for (int i = 0; i < n; ++i) suma += v[i];
  return suma;
}

int comptatge_frontisses(const vector<int> &v)
{
  /* Pre: cert */
  /* Post: el resultat es el nombre d'elements frontissa de v */
  int front = 0, s_ant = 0, s_seg = suma_el(v), n = v.size();
  for (int i = 0; i < n; ++i) {
    s_seg -= v[i];
    if ((s_seg - s_ant) == v[i]) ++front;
    s_ant += v[i];
  }
  return front;
}