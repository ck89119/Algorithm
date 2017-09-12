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
  vector<pair<int, int>> find_index(string s, vector<string> &dict) {
    vector<pair<int, int>> ans;
    for (auto word: dict)
      for (int i = 0; i < s.size(); ++i) {
        int flag = true;
        for (int j = 0; j < word.size(); ++j)
          if (s[i+j] != word[j]) {
            flag = false;
            break;
          }
        if (flag) {
          ans.push_back(make_pair(i, i + word.size()));
        }
      }
    return ans;
  }

  string addBoldTag(string s, vector<string>& dict) {
    auto index = find_index(s, dict);
    if (index.size() == 0) return s;

    sort(index.begin(), index.end());
    // for (auto p: index)
    //   cout << p.first << ' ' << p.second << endl;

    string ans; 
    int l = 0;
    pair<int, int> cur = index[0];
    for (auto p: index) {
      if (p.first > cur.second) {
        ans += s.substr(l, cur.first - l);
        ans += "<b>";
        ans += s.substr(cur.first, cur.second - cur.first);
        ans += "</b>";
        l = cur.second;
        cur = p;
      } else {
        cur.second = max(cur.second, p.second); 
      }
    }
    ans += s.substr(l, cur.first - l);
    ans += "<b>";
    ans += s.substr(cur.first, cur.second - cur.first);
    ans += "</b>";
    ans += s.substr(cur.second);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  string s = "abcxyz123";
  vector<string> dict;
  dict.push_back("abc");
  dict.push_back("123");
  Solution solu;
  cout << solu.addBoldTag(s, dict) << endl; 
  return 0;
}
