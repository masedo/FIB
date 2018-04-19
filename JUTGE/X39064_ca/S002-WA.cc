#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
  int x, y;
};

int distancia (const Punto& a, const Punto& b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int distancia_minima(const Punto& P, int Y, int X) {
  Punto esq1;
  esq1.y = 0;
  esq1.x = 0;
  
  Punto esq2;
  esq2.y = 0;
  esq2.x = X - 1;
  
  Punto esq3;
  esq3.y = Y - 1;
  esq3.x = 0;
  
  Punto esq4;
  esq4.y = Y - 1;
  esq4.x = X - 1;
  
  Punto esq5;
  esq5.y = X / 2;
  esq5.x = Y / 2;
  
  return 
  min (
      min (
	min(distancia(P, esq1), distancia(P, esq2)), 
	min(distancia(P, esq3), distancia(P, esq4))
      ),
      distancia(P, esq5)
  ) % 10;
  
}

int main()
{
  bool primer = true;
  int Y, X;
  while (cin >> Y >> X) {
    if (primer) primer = false;
    else cout << endl;
    
    for (int y = 0; y < Y; ++y) {
      for (int x = 0; x < X; ++x) {
	Punto P;
	P.x = x;
	P.y = y;
	cout << distancia_minima(P, Y, X);
      }
      cout << endl;
    }
  }
  
}
