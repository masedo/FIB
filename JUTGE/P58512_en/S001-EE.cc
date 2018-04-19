#include <iostream>
using namespace std;

int min_days(double m, double f, double p, double days, double a) {
    a = a*p;
    if (m+(f*days) < a) return days;
    else return min_days(m,f,p,days+1,a);
}


int main() {
    double m, f, p;
    while (cin >> m >> f >> p) {
        double days = 1;
        p = 1 + (p/100);
        if (m+f > m*p) days = min_days(m,f,p,days+1,(m*p));
        cout << days << endl;
    }
}