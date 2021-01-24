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
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define LL long long
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n;
LL a[8];
int divisorNum[8], primeCount;
int res;

int rec(int cur, vector<LL> &tree, int rootPrimeNum, int rootChildNum) {
    int i;
    if (cur == n) {
        res = min(res, n+rootPrimeNum+(rootChildNum!=1)-primeCount);
        return 0;
    }
    for (i = 0; i < tree.size(); i++)
        if (tree[i]%a[cur] == 0) {
            tree[i] /= a[cur];
            tree.push_back(a[cur]);
            rec(cur+1, tree, rootPrimeNum+(i==0?divisorNum[cur]:0), rootChildNum+(i==0));
            tree.pop_back();
            tree[i] *= a[cur];
        }
    return 0;
}

int cmp(const LL &a, const LL &b) {
    return a>b;
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a+n, cmp);
    CLR(divisorNum, 0); primeCount = 0;
    for (i = 0; i < n; i++) {
        LL t = a[i];
        for (j = 2; (LL)1*j*j <= t; j++)
            while (t%j == 0) {
                divisorNum[i]++;
                t /= j;
            }
        if (t != 1) divisorNum[i]++;
        if (divisorNum[i] == 1) primeCount++;
    }
    //dump(primeCount)
    vector<LL> tree;
    tree.push_back(0);
    res = INF;
    rec(0, tree, 0, 0);
    printf("%I64d\n", res);
    return 0;
}
