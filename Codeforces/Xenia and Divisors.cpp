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
//#include <algorithm>
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

int count[8];
int n;

int main() {
    int i;
    cin >> n;
    CLR(count, 0);
    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        count[tmp]++;
    }
    if (count[5] > 0 || count[7] > 0) {
        cout << -1 << endl;
        return 0;
    }
    if (count[1] ==  count[2]+count[3] && count[1] == count[4]+count[6] && count[2] >= count[4] && count[6] >= count[3]) {
        for (i = 0; i < count[4]; i++)
            cout << 1 << ' ' << 2 << ' ' << 4 << endl;
        count[1] -= count[4]; count[2] -= count[4];
        for (i = 0 ; i < count[2]; i++)
            cout << 1 << ' ' << 2 << ' ' << 6 << endl;
        count[1] -= count[2]; count[6] -= count[2];
        for (i = 0 ; i < count[1]; i++)
            cout << 1 << ' ' << 3 << ' ' << 6 << endl;
    } else {cout << -1 << endl;}


    return 0;
}
