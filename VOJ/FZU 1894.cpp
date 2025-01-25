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

int t;
int q[1000005], tail, head, index[100005];

int input() {
    char str[10];
    int k, k1;
    scanf("%s", str);
    head = tail = 0;
    k1 = k = 0;
    while (str[0] != 'E') {
        if (str[0] != 'S') {
            if (str[0] == 'C') {
                int v;
                scanf("%s %d", str, &v);//dump(v)
                while (head < tail && q[tail-1] < v) tail--;
                q[tail] = v;
                index[tail++] = k++;
            }
            if (str[0] == 'Q') {
                if (tail > head)
                    printf("%d\n", q[head]);
                else printf("-1\n");
            }
            if (str[0] == 'G') {
                k1++;
                while (head < tail && index[head] < k1) head++;
            }
        }
        scanf("%s", str);
    }
    return 0;
}

int main(){
    scanf("%d", &t);
    while (t--) {
        input();
    }
    return 0;
}
