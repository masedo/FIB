#include <iostream>
using namespace std;
int main() {
  int a, r;
  cin>>a;
  cout<<"nombres que acaben igual que "<<a<<":"<<endl;
  r=a%1000;
  int cont=0; 
  while (cin>>a) {
    if ((a%1000)==r) {
      cont=cont+1;
      cout<<a<<endl;
    }
  }
  cout<<"total: "<<cont<<endl;
}
    
    
    