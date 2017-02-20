#include <bits/stdc++.h>
using namespace std;

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class Solution {
public:
    unordered_map<string, vector<string> > dict;
    unordered_map<string, int> word_best_depth;
    
    void build_dict(unordered_set<string> &wordList) {
      for (auto word: wordList) {
        auto &next_words = dict[word];
        for (int i = 0; i < word.size(); ++i) {
          string next_word = word;
          for (char ch = 'a'; ch <= 'z'; ++ch) {
            next_word[i] = ch;
            if (wordList.find(next_word) != wordList.end()) {
              next_words.push_back(next_word);
            }
          }
        }
      }
    }

    void build_word_best_depth(unordered_set<string> &wordList) {
      int max_depth = wordList.size() + 2;
      for (auto word: wordList)
        word_best_depth[word] = max_depth;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
      wordList.insert(beginWord);
      wordList.insert(endWord);
      build_dict(wordList); 
      build_word_best_depth(wordList);
      // for (auto it: dict) {
      //   cout << it.first << ": ";
      //   out(it.second);
      // }
      
      vector<vector<string> > ans;
      queue<vector<string> > q;
      vector<string> begin(1, beginWord);
      word_best_depth[beginWord] = 1;
      q.push(begin);      
      while (!q.empty()) {
        auto words = q.front(); q.pop();
        int depth = words.size();
        string last_word = words[depth - 1]; 
        if (last_word == endWord) {
          ans.push_back(words);
        } 
        
        for (auto word: dict[last_word]) {
          if (word_best_depth[word] < depth) continue;
          word_best_depth[word] = depth;
          vector<string> tmp(words);
          tmp.push_back(word);
          q.push(tmp);
        }
      }
      return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  Solution *s = new Solution();
  string beginWord = "hot";
  string endWord = "dog";
  unordered_set<string> wordList;
  wordList.insert("hot");
  wordList.insert("dog");
  wordList.insert("dot");
  // dump("$$$$");
  auto ans = s->findLadders(beginWord, endWord, wordList);
  for (auto it: ans)
    out(it);
  return 0;
}
