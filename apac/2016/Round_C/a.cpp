#include <bits/stdc++.h>
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
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int s[N];
int n, m, p;

int main() {
#ifndef ONLINE_JUDGE
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  for (int ncase = 1; ncase <= t; ++ncase) {
    printf("Case #%d:\n", ncase);
    map<string, vector<int> > scores;
    scanf("%d", &p);
    for (int i = 0; i < p; ++i)
      scanf("%d", &s[i]);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int w;
      scanf("%d", &w);
      for (int j = 0; j < p; ++j) {
        char name[14];
        scanf("%s", name);
        string str_name = string(name);
        scores[str_name].pb(w * s[j]);
      }
    }
    scanf("%d", &m);

    vector<pair<int, string> > rank;
    for (auto& it: scores) {
      // dump(it.first); out(it.second);
      vector<int>& v = it.second;
      int sum = 0;
      sort(v.begin(), v.end());
      for (int i = 1; i <= m && i <= v.size(); ++i)
        sum += v[v.size()-i];
      rank.pb(mp(-sum, it.first));
    }
    
    // dump(rank.size());
    sort(rank.begin(), rank.end());
    int r;
    for (int i = 0; i < rank.size(); ++i) {
      if (i == 0 || rank[i].first != rank[i-1].first)
        r = i + 1;
      printf("%d: %s\n", r, rank[i].second.c_str());
    }

  }
  return 0;
}
