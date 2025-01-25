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

map<char, map<char, string>> t {
  {'A', {
    {'A', "A"},
    {'^', "<A"},
    {'>', "vA"},
    {'v', "<vA"},
    {'<', "v<<A"},
  }},
  {'^', {
    {'A', ">A"},
    {'^', "A"},
    {'>', "v>A"},
    {'v', "vA"},
    {'<', "v<A"},
  }},
  {'>', {
    {'A', "^A"},
    {'^', "<^A"},
    {'>', "A"},
    {'v', "<A"},
    {'<', "<<A"},
  }},
  {'v', {
    {'A', "^>A"},
    {'^', "^A"},
    {'>', ">A"},
    {'v', "A"},
    {'<', "<A"},
  }},
  {'<', {
    {'A', ">>^A"},
    {'^', ">^A"},
    {'>', ">>A"},
    {'v', ">A"},
    {'<', "A"},
  }},
};

map<string, map<int, ll>> f; 

ll solve(const string &s, int level) {
  if (f.find(s) != f.end() && f[s].find(level) != f[s].end()) {
    return f[s][level];
  }

  if (level == 26) return 1;

  ll ans = 0;
  auto pre = 'A';
  for (auto ch: s) {
    ans += solve(t[pre][ch], level + 1);
    pre = ch;
  }
  
  // cout << "[" << level << "]" << "pre: " << pre << ", s: " << s << ", ans: " << ans << endl;
  return f[s][level] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  vector<string> vec; 
  auto f = [&]() {
    ll ans = 0;
    for (auto &s : vec) {
        ans += solve(s, 0);
      }
    return ans;
  }; 

  // 129A
  vec = {"^<<A", ">A", "^^>A", "vvvA"};
  dump(f());

  // 176A
  vec = {"^<<A", "^^A", "v>>A", "vvA"};
  dump(f());

  // 985A
  vec = {"^^^A", "<A", "vA", "vv>A"};
  dump(f());

  // 170A
  vec = {"^<<A", "^^A", ">vvvA", ">A"};
  dump(f());

  // 528A
  vec = {"<^^A", "vA", "^^A", "vvv>A"};
  dump(f());
  return 0;
}
