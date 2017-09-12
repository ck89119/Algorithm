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
    int t;
    is >> t;
    return t;
  }

  string int2str(int t) {
    ostringstream os;
    os << t;
    return os.str();
  }

  pair<int, int> parse(string s) {
    int n = s.size();
    if (s[n-1] == 'x') {
      if (s == "+x") return make_pair(0, 1);
      if (s == "-x") return make_pair(0, -1);
      return make_pair(0, str2int(s.substr(0, n-1)));
    }
    return make_pair(1, str2int(s));
  }

  int split(string s, int a[2]) {
    if (s[0] != '-' && s[0] != '+') {
      s = '+' + s;
    }
    
    int l = 0, r = 1;
    while (r < s.size()) {
      if (s[r] == '-' || s[r] == '+') {
        auto ans = parse(s.substr(l, r-l));
        a[ans.first] += ans.second;
        l = r;
      }
      ++r;
    }
    auto ans = parse(s.substr(l, r-l));
    a[ans.first] += ans.second;
    return 0; 
  }

  string solveEquation(string equation) {
    int left[2], right[2];
    clr(left, 0), clr(right, 0);
    string left_eq, right_eq;
    for (int i = 0; i < equation.size(); ++i) {
      if (equation[i] == '=') {
        left_eq = equation.substr(0, i);
        right_eq = equation.substr(i+1);
      } 
    }
    
    split(left_eq, left);
    split(right_eq, right);
    left[0] -= right[0];
    right[1] -= left[1];
    if (left[0] == 0 && right[1] == 0) return "Infinite solutions";
    if (left[0] == 0 && right[1] != 0) return "No solution";
    return "x=" + int2str(right[1] / left[0]);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;  
  cout << s.solveEquation("x+5-3+x=6+x-2") << endl;
  cout << s.solveEquation("x=x") << endl;
  cout << s.solveEquation("2x=x") << endl;
  cout << s.solveEquation("2x+3x-6x=x+2") << endl;
  cout << s.solveEquation("x=x+2") << endl;
  return 0;
}
