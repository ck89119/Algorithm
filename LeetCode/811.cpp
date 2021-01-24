#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
 public:
  int str2int(string s) {
    istringstream is(s);
    int n;
    is >> n;
    return n;
  }

  string int2str(int n) {
    ostringstream os;
    os << n;
    return os.str();
  }

  vector<string> subdomainVisits(vector<string>& cpdomains) {
    map<string, int> count;
    for (auto cpdomain: cpdomains) {
      int i = 0;
      int n = cpdomain.size();
      while (i < n && cpdomain[i] != ' ') ++i;
      int cnt = str2int(cpdomain.substr(0, i));

      for (++i; i < n; ++i) {
        count[cpdomain.substr(i)] += cnt;
        while (i < n && cpdomain[i] != '.') ++i;
      }
    }

    vector<string> ans;
    for (auto p: count)
      ans.push_back(int2str(p.second) + " " + p.first);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
