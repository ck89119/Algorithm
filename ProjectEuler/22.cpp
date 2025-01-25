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

vector<string> split(const string &s, char delim) {
  vector<string> ans;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    ans.push_back(item.substr(1, item.size()-2));
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  auto names = split(s, ',');
  sort(names.begin(), names.end());
  
  int ans = 0;
  for (int i = 0; i < names.size(); ++i) {
    int sum = 0;
    for (auto ch: names[i]) sum += ch - 'A' + 1;
    ans += sum * (i+1); 
  }
  cout << ans << endl;
  return 0;
}
