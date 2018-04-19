#include <iostream>
#include <cmath>
using namespace std;

int min_days(double m, double f, double p) {
    int days = 1, daysL, daysR = 1;
    while ((m+(f*daysR) > m*pow(p,daysR))) daysR *= 2;
    daysL = daysR/2;
    if (m+f > m*p) ++days;
    while (daysL < daysR and daysR-daysL > 1) {
        days = (daysL+daysR)/2;
        if (m+(f*days) < m*pow(p,days)) daysR = days;
        else daysL = days;        
    }
    return days;
}


int main() {
    double m, f, p;
    while (cin >> m >> f >> p) {
        p = 1 + (p/100);
        cout << min_days(m,f,p) << endl;
    }
}