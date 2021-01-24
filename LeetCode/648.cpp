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
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Trie {
  int root;
  vector<vector<int>> nxt;
  vector<string> end;
  
  Trie() {
    root = new_node();
  }

  int new_node() {
    vector<int> v(26, -1);
    nxt.push_back(v);
    end.push_back("");
    return end.size()-1; 
  }

  int insert(string s) {
    int cur = root;
    for (auto ch: s) {
      if (nxt[cur][ch-'a'] == -1) {
        nxt[cur][ch-'a'] = new_node();
      }
      cur = nxt[cur][ch-'a']; 
    }
    end[cur] = s;
    return 0;
  }

  string search(string s) {
    int cur = root;
    for (auto ch: s) {
      if (end[cur] != "") return end[cur];
      if (nxt[cur][ch-'a'] == -1) return s;
      cur = nxt[cur][ch-'a'];
    }
    return s;
  }
};

class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    Trie trie;
    for (auto s: dict) 
      trie.insert(s);
    string ans;
    auto words = split(sentence, ' ');
    for (auto word: words) {
      dump(word);
      word = trie.search(word);
      dump(word);
      ans += word + " ";
    }
    return ans.substr(0, ans.size()-1);
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
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Solution s;
  vector<string> dict;
  dict.push_back("cat");
  dict.push_back("bat");
  dict.push_back("rat");
  cout << s.replaceWords(dict, "the cattle was rattled by the battery") << endl;
  return 0;
}
