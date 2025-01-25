#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> kmp(const string &s, const string &p) {
  // fail[i] means the end index of the longest prefix of b,
  // which equals one of the suffixes of b[0..i]
  vector<int> fail(p.size());
  // kmp[i] means the end index of the longest prefix of b,
  // which equals one of the suffixes of a[0..i]
  vector<int> ans(s.size());

  int j;
  fail[0] = j = -1;
  for (int i = 1; i < p.size(); ++i) {
    while (j >= 0 && p[i] != p[j+1]) j = fail[j];
    if (p[i] == p[j+1]) ++j;
    fail[i] = j;
  }
  // out(fail);

  j = -1;
  for (int i = 0; i < s.size(); ++i) {
    // dump(s[i]);
    // dump(p[j+1]);
    while (j >= 0 && s[i] != p[j+1]) j = fail[j];
    if (s[i] == p[j+1]) ++j;
    ans[i] = j;
  }
  // out(ans);
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  // kmp("abc", "ab");
  // string a = "dababcbabc", b = "abc";
  string a = "aaaa", b = "aa";
  auto match = kmp(a, b);
  out(match);
  for (int i = 0; i < match.size(); ++i) {
    if (match[i] == b.size() - 1) cout << i - match[i] << endl;
  }
  return 0;
}
