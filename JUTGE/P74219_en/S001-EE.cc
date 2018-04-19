#include <iostream>
using namespace std;


int fib(int k) {
    if (k == 0) return 0;
    else if (k == 1) return 1;
    else return fib(k-1) + fib(k-2);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        n = n%m;
        cout << fib(n)%m<<endl;
    }
}
        