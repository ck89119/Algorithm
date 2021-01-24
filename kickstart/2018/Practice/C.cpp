#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

// template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
// template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
map<string, string> out;
map<string, int> indgree;

int main() {
#ifndef ONLINE_JUDGE
  freopen("C-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    out.clear();
    indgree.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      string a, b;
      cin >> a >> b;
      // dump(a), dump(b);
      out[a] = b;
      ++indgree[b];
      if (indgree.find(a) == indgree.end()) indgree[a] = 0;
    }

    printf("Case #%d:", ncase);
    string s;
    for (auto p: indgree)
      if (p.second == 0) {
        s = p.first;
        break;
      }
    while (out.find(s) != out.end()) {
      printf(" %s-%s", s.c_str(), out[s].c_str());
      s = out[s];
    }
    printf("\n");
  }
  return 0;
}
