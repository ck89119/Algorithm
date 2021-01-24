#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
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
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution { 
 public:
  int get_v(char c) {
    if (c == 'A') return 0;
    else if (c == 'C') return 1;
    else if (c == 'T') return 2;
    return 3;
  }

  vector<string> findRepeatedDnaSequences(string s) {
    int n = s.size();
    vector<string> ans;
    if (n <= 10) return ans;
    
    map<long long, vector<int>> m;
    long long t = 0;
    for (int i = 0; i < 10; ++i)
      t = (t << 2) + get_v(s[i]);
    m[t].push_back(0);

    for (int i = 1; i <= n - 10; ++i) {
      t = (t << 2) + get_v(s[i+9]);
      t = t & 0xfffff;
      m[t].push_back(i);
    }

    for (auto it: m)
      if (it.second.size() > 1) 
        ans.push_back(s.substr(it.second[0],10));
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  for (auto s: s.findRepeatedDnaSequences("AAAAAAAAAAAA"))
    cout << s << endl;
  return 0;
}
