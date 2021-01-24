/*
ID: ck89119
PROG: cowxor
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
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("cowxor.in","r",stdin);
#define fout freopen("cowxor.out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=500005;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

struct Trie {
    int total, root, child[MAXN][2];
    int index[MAXN], value[MAXN];
    Trie() {
        total = 0;
        root = total;
        CLR(child[total++], -1);
        index[root] = -1;
        value[root] = -1;
    }

    int insert(int x, int idx) {
        int i;
        int cur = root;
        for (i = 20; i >= 0; --i) {
            int bit = ((x & (1 << i)) >> i);
            if (child[cur][bit] == -1) {
                child[cur][bit] = total;
                CLR(child[total++], -1);
            }
            cur = child[cur][bit];
            //dump(i)
        }
        index[cur] = idx;
        value[cur] = x;
    }


};

int n;
int ans, ans_i, ans_j;
int a[100005];
Trie trie;

int input() {
    cin >> n;
    return 0;
}

int find_max(int x) {
    int i, loc = trie.root;
    for (i = 20; i >= 0 && loc != -1; --i) {
        int bit = ((x & (1 << i)) >> i);
        if (trie.child[loc][bit^1] != -1) {
            loc = trie.child[loc][bit^1];
        }
        else loc = trie.child[loc][bit];
    }
    return loc;
}

int solve() {
    int i;
    int x;
    a[0] = 0;
    trie.insert(a[0], 0);
    //dump("####")
    ans = -1;
    for (i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = a[i-1] ^ x;
        int t = find_max(a[i]);
        //dump(i)
        //dump(a[i])
        //dump(trie.index[t])
        if (t != -1 && (a[i] ^ trie.value[t]) > ans) {
            ans = a[i] ^ trie.value[t];
            ans_i = trie.index[t] + 1;
            ans_j = i;
        }
        trie.insert(a[i], i);
    }
    return 0;
}

int output() {
    cout << ans << ' ' << ans_i << ' ' << ans_j << endl;
    return 0;
}

int main() {
    fin fout
    ios :: sync_with_stdio(false);
    cout << fixed << setprecision(16);
    input();
    solve();
    output();
    return 0;
}
