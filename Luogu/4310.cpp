#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
typedef long long ll;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 1000000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
int cnt[30];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; ++i) {
    int x, len = 0;
    scanf("%d", &x);
    for (int j = 0; j < 30; ++j) 
      if ((x >> j) & 1) {
        len = max(len, cnt[j]);
      }
    for (int j = 0; j < 30; ++j) 
      if ((x >> j) & 1) {
        cnt[j] = len + 1;
      }
  }
  printf("%d\n", *max_element(cnt, cnt+30));
  return 0;
}