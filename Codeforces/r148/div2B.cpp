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

int n, q;
string s;
int l, r;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  cin >> n >> q;
  cin >> s;
  while (q--) {
    int cnt[10];
    string ss;
    CLR(cnt, 0);
    ss = s;
    
    int cp, dp;
    cin >> l >> r;
    dp = 1; cp = l;
    for (int i = l; i <= r; ++i) {
      if (s[i] >= '1' && s[i] <= '9') {
        ++cnt[s[i]-'0'];
        --s[i];
      } else if (s[i] == '0') {
        ++cnt[0];
        s[i] = ' ';
      } else {
        
      }
    
    } 


    for (int i = 0; i < 10; ++i)
      cout << cnt[i] << ' ';
    cout << endl;
  
  }
  return 0;
}
