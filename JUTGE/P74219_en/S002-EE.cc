#include <iostream>
using namespace std;


int fib(int k, int m) {
    if (k%m == 0) return 0;
    else if (k%m == 1) return 1;
    else return fib((k%m)-1,m) + fib((k%m)-2,m);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << fib(n%m, m)<<endl;
    }
}
        