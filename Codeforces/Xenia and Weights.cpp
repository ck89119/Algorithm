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
#define PB push_back
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

string s;
int m;
int res[1005];

int input() {
    int i;
    cin >> s;
    cin >> m;
    return 0;
}

int solve() {
    int i, j, k;
    int s1, s2, pre;
    int sum;

    for (k = 0; k < 10; k++) {
        sum = 0; s1 = s2 = 0; pre = -1;
        if (s[k] == '0') continue;
        s1 += k+1; res[sum++] = k+1; pre = k+1;
        //dump(k+1)
        while (sum < m) {
            if (s1 <= s2) {
                for (i = 0; i < s.size(); i++)
                    if (s[i] == '1' && i+1 != pre && s1+i+1 > s2) {
                        s1 += i+1;
                        res[sum++] = i+1;
                        pre = i+1;
                        break;
                    }
                if (i >= s.size()) break;
            }
            else {
                for (i = 0; i < s.size(); i++)
                    if (s[i] == '1' && i+1 != pre && s2+i+1 > s1) {
                        s2 += i+1;
                        res[sum++] = i+1;
                        pre = i+1;
                        break;
                    }
                if (i >= s.size()) break;
            }
            //dump(s1)dump(s2)
        }
        if (sum >= m) break;
    }

    if (sum >= m) {
        cout << "YES" << endl;
        for (i = 0; i < m; i++)
            cout << res[i] << ' ';
        cout << endl;
    } else cout << "NO" << endl;

    return 0;
}

int main() {
    input();
    solve();
    return 0;
}
