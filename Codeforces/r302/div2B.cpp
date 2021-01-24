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
    //freopen("out.txt", "w", stdout);
  #endif
  
  int k, n;
  cin >> k >> n;
  if (n > k* k - k * k / 2) {
    cout << "NO" << endl;
    return 0;
  }

  int cnt = 0;
  vector<string> m;
  for (int i = 0; i < k; ++i) {
    string s = string(k, 'S');
    m.push_back(s);
  }
  for (int i = 0; i < k && cnt < n; ++i)
    for (int j = i & 1; j < k && cnt < n; j += 2) {
      m[i][j] = 'L';
      ++cnt;
    }
  cout << "YES" << endl;
  for (int i = 0; i < k; ++i)
    cout << m[i] << endl;

  return 0;
}
