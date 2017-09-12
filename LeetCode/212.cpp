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

struct Trie {
  struct Node {
    int next[26];
    bool is_word;
    string word;

    Node(): is_word(false) {
      clr(next, -1);
    }
  };
  vector<Node> nodes;
  int root;

  Trie() {
    root = new_node();
  }

  int new_node() {
    Node node;
    nodes.push_back(node);
    return nodes.size() - 1;
  }

  int insert(const string &word) {
    int cur = root;
    for (auto ch: word) {
      if (nodes[cur].next[ch-'a'] == -1)
        nodes[cur].next[ch-'a'] = new_node();
      cur = nodes[cur].next[ch-'a'];
    }
    nodes[cur].is_word = true;
    nodes[cur].word = word;
    return 0;
  }
};


class Solution {
 public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  int inboard(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  int dfs(vector<Trie::Node> &nodes, int cur, vector<vector<char>> &board, int x, int y, vector<vector<bool>> &visited, set<string> &ans) {
    if (nodes[cur].is_word) ans.insert(nodes[cur].word);
    for (int i = 0; i < 26; ++i)
      if (nodes[cur].next[i] != -1)
        for (int k = 0; k < 4; ++k) {
          int tx = x + dx[k];
          int ty = y + dy[k];
          if (inboard(tx, ty, board.size(), board[0].size()) && !visited[tx][ty] && board[tx][ty] == 'a' + i) {
            visited[tx][ty] = true;
            dfs(nodes, nodes[cur].next[i], board, tx, ty, visited, ans);
            visited[tx][ty] = false;
          }
        }
    return 0;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int n = board.size();
    int m = board[0].size();

    vector<pair<int, int>> start[26];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        start[board[i][j]-'a'].push_back(make_pair(i, j));

    Trie trie;
    for (auto word: words) trie.insert(word);
    
    set<string> ans;
    for (int i = 0; i < 26; ++i) {
      int k = trie.nodes[trie.root].next[i]; 
      if (k == -1) continue;
      for (auto p: start[i]) {
        int x = p.first;
        int y = p.second;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[x][y] = true;
        dfs(trie.nodes, k, board, x, y, visited, ans);
      }
    }

    return vector<string>(ans.begin(), ans.end());
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  vector<vector<char>> board;
  string str = "oaan";
  board.push_back(vector<char>(str.begin(), str.end()));
  str = "etae";
  board.push_back(vector<char>(str.begin(), str.end()));
  str = "ihkr";
  board.push_back(vector<char>(str.begin(), str.end()));
  str = "iflv";
  board.push_back(vector<char>(str.begin(), str.end()));

  vector<string> words;
  words.push_back("oath");
  words.push_back("pea");
  words.push_back("eat");
  words.push_back("rain");
  words.push_back("thf");

  Solution s;
  out(s.findWords(board, words));
  return 0;
}
