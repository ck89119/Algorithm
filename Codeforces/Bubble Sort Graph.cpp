/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

int n, a[100005];
int ans = 0;
int f[100005], fSize;

int BinarySearch(int v) {
    int l, r, m;
    l = 0; r = fSize - 1;
    while (l <= r) {
        m = (l + r) >> 1;
        if (f[m] < v) l = m + 1;
        else r = m - 1;
    }
    return l;
}

int LIS() {
    int i;
    fSize = 0; f[fSize++] = -INF;
    for (i = 0; i < n; i++) {
        //dump(i)
        if (a[i] > f[fSize-1]) {
            f[fSize++] = a[i];
        }
        else {
            int pos = BinarySearch(a[i]);
            f[pos] = a[i];
        }
    }
    cout << fSize-1 << endl;
    return 0;
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    LIS();
    return 0;
}
