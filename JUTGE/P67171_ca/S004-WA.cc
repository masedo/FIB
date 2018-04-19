#include <iostream>
using namespace std;


int main() {
  int h, m;
  while (cin >> h >> m) {
    if (h >= 12) h = h-12;
    int cam = 0, min = 0;
    
    if (m == 0) {
      if (h == 0) cam = 12;
      else if (h == 1) {
	cam = 5;
	min = 60;
      }
      else cam = h;
    }
    else if (h < 1) {
      if (m <= 15) {
	cam = 7;
	min = (60-m)+45;
      }
      else if (m <= 30) {
	cam = 8;
	min = (60-m)+60;
      }
      else if (m <= 45) {
	cam = 7;
	min = (60-m)+60;
      }
      else {
	cam = 5;
	min = (60-m)+60;
      }
    }
    else {
      if (m <= 15) cam = 3;
      else if (m <= 30) cam = 2;
      else if (m <= 45) cam = 1;
      cam = cam + (h+1);
      min = (60-m);
    }  
    cout << min << " " << cam << endl;
  }
}