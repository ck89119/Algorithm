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
#define CL(a,x) memset(a,x,sizeof(a))
#define MP(A,B) make_pair(A,B)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
//freopen("","r",stdin);
//freopen("","w",stdout);
//ifstream fin("");
//ofstream fout("");
//struct Edge {
//    int to;
//    int w;
//    int next;
//};
//int head[];
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;
struct NODE{
    int a, b;
    int i;
};

int n, p, k;
NODE n1[100005], n2[100005];
int index1[100005], index2[100005];

int cmp1(const NODE &a, const NODE &b) {
    if (a.a != b.a) return a.a > b.a;
    else return a.b > b.b;
}

int cmp2(const NODE &a, const NODE &b) {
    return a.b < b.b;
}

int input() {
    int i;
    scanf("%d%d%d", &n, &p, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &n1[i].a, &n1[i].b);
        n1[i].i = i;
        n2[i].a = n1[i].a; n2[i].b = n1[i].b;
        n2[i].i = n1[i].i;
    }
    sort(n1+1, n1+n+1, cmp1);
    sort(n2+1, n2+n+1, cmp2);

    for (i = 1; i <= n; i++)
        index1[i] = n1[i].i;
    for (i = 1; i <= n; i++)
        index2[n2[i].i] = i;
//    for (i = 1; i <= n; i++) cout << index1[i]<< ' '; cout << endl;
//    for (i = 1; i <= n; i++) cout << index2[i]<< ' '; cout << endl;
    return 0;
}

int solve() {
    int i, j, kk;
    int minIndex;
    minIndex = INF;
    kk = 1;
    //dump(p)dump(k)
    for (i = 0; i < k; i++) {

        //dump(index2[t])
        //dump(t)
        while (index2[index1[kk]] <= p-k) kk++;
        int t = index1[kk];
        if (index2[t] > p-k) {
            //dump(t);
            cout << t << ' ';
            kk++;
            minIndex = min(minIndex, index2[t]);
        }

    }//dump(minIndex)

    j = minIndex-1;
    for (i = k; i < p; i++) {
        cout << n2[j].i << ' ';
        j--;
    }
    cout << endl;
    return 0;
}


int main(){
    input();
    solve();
    return 0;
}
