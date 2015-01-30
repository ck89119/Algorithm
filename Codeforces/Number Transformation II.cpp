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

int n;
vector <int> x, xs;
map <int, int> xmap;
int a, b;

int main() {
    int i;
    int ans;
    cin >> n;
    for (i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (xmap.count(t) == 0) {
            xmap[t] = 1;
            x.PB(t);
        }
    }
    cin >> a >> b;
    ans = 0;
    while (a != b) {
        xs.clear();
        int bestA = a - 1;
        for (i = 0; i < x.size(); i++) {
            int t = x[i];
            int p = a / t * t;
            if (p >= b) {
                xs.PB(t);
                bestA = min(bestA, p);
            }
        }
        x = xs;
        a = bestA;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
