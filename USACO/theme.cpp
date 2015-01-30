/*
ID: ck89119
PROG: theme
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
#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("theme.in","r",stdin);
#define fout freopen("theme.out","w",stdout);
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

int n;
int s[5005];

int OK(int i, int j, int len) {
    int delta = s[i]-s[j];
    int k;
    int flag = 1;
    for (k = 0; k < len; k++)
        if (s[i+k] - delta == s[j+k]) continue;
        else {
            flag = 0;
            break;
        }
    return flag;
}

int check(int len) {
    int i, j;
    for (i = 0; i <= n - 2 * len; i++)
        for (j = i + len; j <= n - len; j++)
            if (OK(i, j, len)) return 1;
    return 0;
}

int main() {
    int i;
    int ans;
    fin fout
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);

    int l, r;
    l = 0; r = n;
    while (l + 1 < r) {
        int mid = (l+r)>>1;
        //dump(l) dump(r) dump(mid)
        if (r <= 5) {ans = 0; break;}
        if (check(mid)) {
            ans = mid;
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << (ans>=5?ans:0) << endl;
    return 0;
}
