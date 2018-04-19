#include <iostream>
#include <vector>
using namespace std;


struct Punt {
  int x, y;
};

struct Distancia {
  int d;
  vector<Punt> punts();
};

int abs(int a) {
  if (a < 0) return -a;
  else return a;
}

int distancia (Punt a, Punt b) {
  return abs(b.x - a.x) + abs(b.y - a.y);
}

int main() {
  int a, b;
  Punt ref;
  ref.x = a; ref.y = b;
  
  int n;
  cin >> n;
  vector <Distancia> totes_dist(0);
  for (int i = 0; i < n; ++i) {
    //llegim punt i el guardem a p
    Punt p;
    cin >> a >> b;
    p.x = a; p.y = b;
    
    //calculem la seva distancia fins a la referencia
    int dist = distancia (p, ref);
    
    //mirem si la distancia esta al vector de totes les distancies
    //si esta, guardem el punt al vector de punts de la seva distancia
    bool esta_dins = false;
    for (int j = 0; j < totes_dist.size(); ++j) {
      if (totes_dist[j].d == dist) {
	totes_dist[j].punts.push_back(p);
	esta_dins = true;
      }
    }
    
    //si la distancia no es eta dins del vector, la fiquem, i tambe
    //fiquem el punt dins de la seva distancia
    if (not esta_dins) {
      Distancia d;
      d.d = dist;
      vector <Punt> d.punts(0);
      d.punts.push_back(p);
      totes_dist.push_back(d);
    }
  }
  
  //llegim el vector de les distancies i fem els cout corresponents
  for (int i = 0; i < totes_dist.size(); ++i) {
    cout << "punts a distancia " << totes_dist[i].d << endl;
    for (int j = 0; j < totes_dist[i].punts.size(); ++j) {
      cout << totes_dist[i].punts.[j].x << " " << totes_dist[i].punts.[j].y;
      cout << endl;
    }
  }
}
    
    
    
  