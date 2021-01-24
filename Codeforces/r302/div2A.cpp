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
const int N = 99999;
const int M = 9999999;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
  #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txtk, "w", stdout);
  #endif
  
  int k;
  string q, ans[30];
  int vis[26];
  int cur;
  cin >> k >> q;
  cur = 0; CLR(vis, 0);
  for (int i = 0; i < k - 1; ++i) {
    vis[q[cur] - 'a'] = 1;
    int l = 1;
    while (cur + l < q.size() && vis[q[cur+l] - 'a']) ++l;
    if (cur + l >= q.size()) {
      cout << "NO" << endl;
      return 0;
    }
    
    ans[i] = q.substr(cur, l);
    cur += l;
  }
  ans[k-1] = q.substr(cur);
  
  cout << "YES" << endl;
  for (int i = 0; i < k; ++i)
    cout << ans[i] << endl;
  return 0;
}
