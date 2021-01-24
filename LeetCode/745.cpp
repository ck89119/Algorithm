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

class WordFilter {
 public:
  struct Trie {
    struct Node {
      int next[26];
      string word;
      int val;

      Node(): word(""), val(-1) {
        clr(next, -1);
      }
    };
    vector<Node> nodes;
    int root;

    int NewNode() {
      Node node;
      nodes.push_back(node);
      return nodes.size() - 1;
    }

    Trie() {
      root = NewNode();
    }

    int insert(string s, int val) {
      int cur = root;
      for (auto ch: s) {
        int x = ch - 'a';
        if (nodes[cur].next[x] == -1) {
          int y = NewNode();
          nodes[cur].next[x] = y;
        }
        cur = nodes[cur].next[x];
      }
      nodes[cur].word = s;
      nodes[cur].val = val;
      return 0;
    }

    int query(string prefix, string suffix) {
      int ans = -1;
      int cur = root;
      for (auto ch: prefix) {
        int x = ch - 'a';
        if (nodes[cur].next[x] == -1) return ans;
        cur = nodes[cur].next[x];
      }
      dfs(cur, ans, suffix); 
      return ans;  
    }

    int dfs(int cur, int &ans, const string &suffix) {
      Node &node = nodes[cur];
      if (node.val != -1) {
        string &word = node.word;
        if (word.size() >= suffix.size() && word.substr(word.size()-suffix.size()) == suffix) {
          ans = max(ans, nodes[cur].val); 
        }
      }
      for (int i = 0; i < 26; ++i)
        if (node.next[i] != -1) dfs(node.next[i], ans, suffix);
      return 0;
    }
  };
  Trie trie;

  WordFilter(vector<string> words) {
    for (int i = 0; i < words.size(); ++i) {
      trie.insert(words[i], i);
    }
  }

  int f(string prefix, string suffix) {
    return trie.query(prefix, suffix);
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<string> words = {"apple", "app"};
  WordFilter filter(words);
  cout << filter.f("a", "e") << endl;
  cout << filter.f("b", "") << endl;
  cout << filter.f("a", "p") << endl;
  return 0;
}
