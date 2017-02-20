#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 12 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int f[1<<N];

int num_of_bit(int s) {
  int cnt = 0;
  while (s) {
    cnt += 1;
    s -= lowbit(s);
  }
  return cnt;
}

int search(int s) {
  if (f[s] != -1) return f[s];
  
  int &ans = f[s];
  ans = num_of_bit(s);
  for (int i = 0; i + 2 < 12; ++i) {
    int bit = (1 << i);
    if ((s & bit) && (s & (bit << 1)) && !(s & (bit << 2))
        || !(s & bit) && (s & (bit << 1)) && (s & (bit << 2)))
      ans = min(ans, search(s ^ bit ^ (bit << 1) ^ (bit << 2)));
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  clr(f, -1);
  int t;
  scanf("%d", &t);
  while (t--) {
    char s[N];
    int status = 0;
    scanf("%s", s);
    for (int i = 0; i < 12; ++i)
      status = (status * 2) + (s[i] == 'o');
    printf("%d\n", search(status)); 
  }
  return 0;
}
