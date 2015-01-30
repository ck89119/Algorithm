/*
ID: ck891191
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
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int op[20];
int n, total, outTotal;

int input() {
    cin >> n;
    return 0;
}

int check() {
    int i, p, tmp;
    int ans = 0;
    p = 1; tmp = 1;
    for (i = 1; i < n; i++) {
        if (op[i] == 1 || op[i] == -1) {
            ans += p * tmp;
            tmp = i+1;
            p = op[i];
        }
        else {
            if (i+1 >= 10) tmp = tmp*100 + i + 1;
            else tmp = tmp*10 + i + 1;
        }
    }
    ans += p * tmp;
    return ans;
}

int output() {
    int i;
    cout << "1" ;
    for (i = 1; i < n; i++) {
        if (op[i] == 1) cout << ' ' << '+' ;
        else if (op[i] == -1) cout << ' ' << '-' ;
        else if (op[i] == 0) cout << ' ' << '.' ;
        cout << ' ' << i+1 ;
    }

    cout << endl;
}

int dfs(int k) {
    if (k >= n) {
        if (check() == 0) {
            total++;
            if (outTotal < 20) {
                outTotal++;
                output();
            }
        }
        return 0;
    }

    op[k] = 1;
    dfs(k+1);

    op[k] = -1;
    dfs(k+1);

    op[k] = 0;
    dfs(k+1);

    return 0;
}



int solve() {
    outTotal = total = 0;
    dfs(1);
    cout << total << endl;
    return 0;
}

int main(){
    input();
    solve();
    return 0;
}
