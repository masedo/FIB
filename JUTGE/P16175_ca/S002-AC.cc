#include <iostream>
#include <vector>
using namespace std;


struct Parell {
  int valor;
  int pos;
};

typedef vector<Parell> Vec_Com;

Vec_Com suma(const Vec_Com& v1, const Vec_Com& v2) {
  Vec_Com V;
  int s1 = v1.size(), s2 = v2.size();
  int i = 0, j = 0;
  Parell p;
  
  while (i < s1 and j < s2) {    
    if (v1[i].pos == v2[j].pos and v1[i].valor+v2[j].valor == 0) {
      ++i; ++j;
    }
    else if (v1[i].pos == v2[j].pos) {
      p.pos = v1[i].pos;
      p.valor = v1[i].valor + v2[j].valor;
      V.push_back(p);
      ++i; ++j;
    }   
    else if (v1[i].pos < v2[j].pos) {
      p.pos = v1[i].pos;
      p.valor = v1[i].valor;
      V.push_back(p);
      ++i;
    }    
    else {
      p.pos = v2[j].pos;
      p.valor = v2[j].valor;
      V.push_back(p);
      ++j;
    }
  }
  
  while (i < s1) {
    p.pos = v1[i].pos;
    p.valor = v1[i].valor;
    V.push_back(p);
    ++i;
  }
  
  while (j < s2) {
    p.pos = v2[j].pos;
    p.valor = v2[j].valor;
    V.push_back(p);
    ++j;
  }
  
  return V;
}

void llegeix(Vec_Com& v) {
  int n;
  cin >> n;
  
  for (int i = 0; i < n; ++i) {
    int a;
    char c;
    Parell p;
    
    cin >> a;
    p.valor = a;
    cin >> c;
    cin >> a;
    p.pos = a;
    
    v.push_back(p);
  }
}

void escriu(const Vec_Com v) {
  int s = v.size();
  cout << s;
  for (int i = 0; i < s; ++i) 
    cout << " " << v[i].valor << ";" << v[i].pos;
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    Vec_Com v1, v2, v3;
    llegeix(v1);
    llegeix(v2);
    escriu (suma(v1, v2));
  }
}
    
  
  
  
  
  
  
  
  
  
  
  