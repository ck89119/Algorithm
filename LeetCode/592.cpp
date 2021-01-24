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
  int gcd(int a, int b) {
    a = abs(a); b = abs(b); 
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  int lcm(int a, int b) {
    return a * b / gcd(a, b);
  }
    
  int string2int(const string &s) {
    istringstream is(s);
    int t;
    is >> t;
    return t;
  }

  string int2string(int x) {
    ostringstream os;
    os << x;
    return os.str();
  }

  vector<pair<int, int>> split(string s) {
    vector<pair<int, int>> ans;
    int i = 0;
    int l = 0;
    if (s[i] == '-') ++i;
    while (i < s.size()) {
      if (s[i] == '-' || s[i] == '+') {
        int j = l;
        while (j < i && s[j] != '/') ++j;
        int n = string2int(s.substr(l, j - l));
        int d = string2int(s.substr(j + 1, i - j - 1));
        ans.push_back(make_pair(n, d));
        l = i;
      }
      ++i;
    }
    int j = l;
    while (j < s.size() && s[j] != '/') ++j;
    int n = string2int(s.substr(l, j - l));
    int d = string2int(s.substr(j + 1));
    ans.push_back(make_pair(n, d));
    return ans;
  }
  
  int pair_out(const pair<int, int> &p) {
    cout << "<" << p.first << ", " << p.second << ">" << endl;
    return 0;
  }

  pair<int, int> add(pair<int, int> p1, pair<int, int> p2) {
    // pair_out(p1); pair_out(p2);
    int n1 = p1.first, d1 = p1.second;
    int n2 = p2.first, d2 = p2.second;
    // dump(d1), dump(d2);
    int d = lcm(d1, d2);
    n1 *= d / d1;
    n2 *= d / d2;
    // dump(n1), dump(n2);
    return make_pair(n1 + n2, d);
  }

  string fractionAddition(string expression) {
    pair<int, int> ans = make_pair(0, 1);
    for (auto p: split(expression)) {
      ans = add(ans, p);
    }
    int n = ans.first;
    int d = ans.second;
    int x = gcd(n, d);
    n /= x, d /= x;
    return int2string(n) + "/" + int2string(d);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  string expression ="5/3+1/3";
  cout << s.fractionAddition(expression) << endl;
  return 0;
}
