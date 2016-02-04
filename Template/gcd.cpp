#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

template <class T> inline T ext_euclide(T a,T b,T &x,T &y){
    if (a < 0) {
        T d = ext_euclide(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = ext_euclide(a, -b, x, y);
        y = -y;
        return d;
    }
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = ext_euclide(b, a%b, x, y);
        T t = x;
        x = y;
        y = t - (a/b) * y;
        return d;
    }
}

int ext_gcd(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        d = a;
        x = 1; y = 0;
        return 0;
    }
    ext_gcd(b, a%b, d, y, x);
    y -= x * (a / b);
    return 0;
}

int main() {
    int x, y, d;
    //ext_gcd(12, 40, d, x, y);
    d = ext_euclide(12, 40, x, y);
    printf("%d*%d + %d*%d = %d", 12, x, 40, y, d);
    return 0;
}
