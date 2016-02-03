#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define CLR(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A, B) make_pair(A, B)
#define PB(A) push_back(A)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 40000 + 5;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, m, k, t;
int s[N];
vector<int> w[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d%d%d", &n, &m, &k, &t);
  for (int i = 0; i < k; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    w[x].push_back(y);
    ++s[x];
  }
  for (int i = 2; i <= n; ++i) s[i] += s[i-1];

  for (int i = 0; i < t; ++i) {
    int x, y;
    int sum = 0;
    int flag = 0;
    scanf("%d%d", &x, &y);
    for (int j = 0; j < w[x].size(); ++j) {
      if (w[x][j] == y) {
        flag = 1;
        break;
      }
      if (w[x][j] < y) ++sum;
    }
    if (flag) {
      printf("Waste\n");
      continue;
    }

    sum += s[x-1];
    sum = m * (x - 1) + (y - 1) - sum;
    if (sum % 3 == 0) printf("Carrots\n");
    else if (sum % 3 == 1) printf("Kiwis\n");
    else if (sum % 3 == 2) printf("Grapes\n");
  }   
  return 0;
}
