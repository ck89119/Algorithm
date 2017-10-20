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
  int update(string &s, const string &sticker) {
    for (auto ch: sticker)
      if (s[ch-'a'] != 'a') --s[ch-'a'];
    return 0;
  }
    
  int minStickers(vector<string>& stickers, string target) {
    vector<set<string>> dic(26, set<string>());
    for (auto sticker: stickers)
      for (auto ch: sticker)
        dic[ch-'a'].insert(sticker);
    
    string s(26, 'a');
    for (auto ch: target) {
      if (dic[ch-'a'].size() == 0) return -1;
      ++s[ch-'a'];
    }
    
    queue<pair<string, int>> q;
    set<string> visited;
    q.push(make_pair(s, 0));
    visited.insert(s);
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      auto s = p.first;
      int cnt = p.second;
      if (s == "aaaaaaaaaaaaaaaaaaaaaaaaaa") return cnt;
      
      for (int i = 0; i < 26; ++i) {
        if (s[i] == 'a') continue;
        for (auto sticker: dic[i]) {
          string ts(s);
          update(ts, sticker);
          if (visited.find(ts) == visited.end()) {
            q.push(make_pair(ts, cnt+1));
            visited.insert(ts);
          }
        }
      } 
    }
    return -1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<string> stickers;
  // stickers.push_back("with");
  // stickers.push_back("example");
  // stickers.push_back("science");
  // cout << s.minStickers(stickers, "thehat") << endl;
  stickers.push_back("notice"); 
  stickers.push_back("possible"); 
  cout << s.minStickers(stickers, "basicbasic") << endl;
  return 0;
}
