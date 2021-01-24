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
//ifstream fin("");
//ofstream fout("");

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=100005;
const int INF=(1<<30);
const double PI=acos(-1.0);
const double EPS=1e-11;

int n, m, k;
int a[MAXN];

int main(){
    int i;
    int head1, tail1, head2, tail2;
    int q1[MAXN], q2[MAXN];
    int res;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        head1 = tail1 = 0;
        head2 = tail2 = 0;
        int i1, i2;
        i1 = i2 = 0;
        res = 0;
        for (i = 0; i < n; i++) {
            while (head1 < tail1 && a[q1[tail1-1]] < a[i]) tail1--;
            q1[tail1++] = i;
            while (head2 < tail2 && a[q2[tail2-1]] > a[i]) tail2--;
            q2[tail2++] = i;
            //dump(a[q1[head1]])dump(a[q2[head2]])
            //dump(q1[head1])dump(q2[head2])
            while (a[q1[head1]] - a[q2[head2]] > k) {
                if (q1[head1] < q2[head2]) i1 = q1[head1++] + 1;
                else i2 = q2[head2++] + 1;
            }
            //dump(i1)dump(i2)
            if (a[q1[head1]] - a[q2[head2]] >= m) {
                res = max(res, i-max(i1, i2)+1);
            }
        }
        printf("%d\n", res);


    }
    return 0;
}
