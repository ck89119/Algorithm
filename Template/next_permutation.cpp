/*
ID: ck891191
PROG:
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(x) cerr<<__LINE__<<"  "<<#x<<"  :  "<<(x)<<endl;
#define two(X) (1<<(X))
#define towL(X) (((int64)(1))<<(x))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define FOR(i,n) FR(i,0,n)//[0,n)
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)//(a,b]
#define ROF(i,n) RF(i,n,0)//[0,n)
#define CL(a,x) memset(a,x,sizeof(a))

const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
const int n=5;

inline int swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
    return 0;
}

int rev(int a[n], int begin, int end) {
    int i, j;
    for (i = begin; i < end; i++)
        for (j = i+1; j < end; j++)
            if (a[i] > a[j]) swap(a[i], a[j]);
    return 0;
}

int nextPermutation(int a[n]) {
    int i;
    for (i = n-1; i > 0; i--) {
        if (a[i-1] < a[i]) {
            int j = n-1;
            while (a[i-1] >= a[j]) j--;
            swap(a[i-1], a[j]);
            sort(a+i, a+n);
            return 0;
        }
    }
    rev(a, 0, n);
    return 0;
}

int main(){
    int a[n] = {3, 2, 5, 4, 1};
    nextPermutation(a);
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    return 0;
}
