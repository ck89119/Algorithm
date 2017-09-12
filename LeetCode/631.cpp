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

class Excel {
 public:
  Excel(int H, char W) {
    clr(sheet, 0);
  }

  void set(int r, char c, int v) {
    sheet[r][c-'A'] = v;
    op[r][c-'A'].clear();
  }

  int get(int r, char c) {
    if (op[r][c-'A'].empty()) {
      return sheet[r][c-'A'];
    }
    
    int ans = 0;
    for (auto str: op[r][c-'A']) {
      auto x = split(str, ':');
      if (x.size() == 1) {
        auto cor = get_cor(x[0]);
        ans += get(cor.first, cor.second);
      } else {
        auto cor0 = get_cor(x[0]);
        auto cor1 = get_cor(x[1]);
        for (int i = cor0.first; i <= cor1.first; ++i)
          for (char j = cor0.second; j <= cor1.second; ++j)
            ans += get(i, j);
      }
    }
    return ans;
  }

  pair<int, char> get_cor(string s) {
    int n = 0;
    for (int i = 1; i < s.size(); ++i)
      n = n * 10 + s[i] - '0';
    return make_pair(n, s[0]);
  }

  int sum(int r, char c, vector<string> strs) {
    op[r][c-'A'] = strs;
    return get(r, c);
  }

  vector<string> split(const string &s, char delim) {
    vector<string> ans;
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
      ans.push_back(item);
    }
    return ans;
  }

 private:
  int sheet[26][26];
  vector<string> op[26][26];
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Excel obj(3, 'C');
  obj.set(1, 'A', 2);
  vector<string> strs;
  strs.push_back("A1");
  strs.push_back("A1:B2");
  cout << obj.sum(3, 'C', strs) << endl;
  return 0;
}
