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

int n;
map<string, vector<string>> email_names;
map<string, vector<string>> c;
map<string, int> idx;
vector<string> names;

int dfs(string email, set<int> &s, set<string> &v) {
  v.insert(email); 
  for (auto name: email_names[email]) {
    s.insert(idx[name]);
  }
  for (auto e: c[email])
    if (v.find(e) == v.end())
      dfs(e, s, v);
  return 0;
}

int cmp(const set<int> &s1, const set<int> &s2) {
  return *s1.begin() < *s2.begin();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string name, email;
    vector<string> emails;
    int a;
    cin >> name >> a;
    names.push_back(name);
    idx[name] = i;
    while (a--) {
      cin >> email;
      email_names[email].push_back(name);
      emails.push_back(email);
    }
    for (auto e1: emails)
      for (auto e2: emails) {
        if (e1 == e2) continue;
        c[e1].push_back(e2);
      }
  }
  
  set<string> v;
  vector<set<int>> groups;
  for (auto item: email_names) {
    string email = item.first;
    if (v.find(email) == v.end()) {
      set<int> s;
      dfs(email, s, v);
      groups.push_back(s);
    }
  }
  sort(groups.begin(), groups.end(), cmp);
  for (auto g: groups) {
    for (auto i: g)
      cout << names[i] << ' ';
    cout << endl;
  }
  return 0;
}
