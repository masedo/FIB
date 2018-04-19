#include <iostream>
using namespace std;
int main() {
  int a, r;
  cin>>a;
  cout<<"nombres que acaben igual que "<<a<<":"<<endl;
  r=a%1000;
  int cont=0; 
  while (cin>>a) {
  cout<<a<<endl;
  if ((a%1000)==r) cont=cont+1;
  }
  cout<<"total: "<<cont<<endl;
}
    
    
    