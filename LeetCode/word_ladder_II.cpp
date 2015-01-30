/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl;
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause");
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin);
#define fout freopen(".out","w",stdout);
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;

class Solution {
public:
  unordered_set<string> *cur, *next;
  unordered_set<string> a, b;
  vector<string> path;
  vector<vector<string> > ans;
  map<string, vector<string> > mp;

  int findNext(unordered_set<string> &dict) {
    unordered_set<string>::iterator it;
    char ch;
    int i;
    for (it = cur->begin(); it != cur->end(); ++it)
      for (i = 0; i < it->size(); ++i) {
        string s = *it;
        for (ch = 'a'; ch <= 'z'; ++ch) {
          s[i] = ch;
          if (dict.count(s)) {
            next->insert(s);
            mp[*it].push_back(s);
          }
        }
      }
    return 0;
  }

  int output(string &start, string &end) {
    if (start == end) {
      ans.push_back(path);
      return 0;
    } else {
      for (int i = 0; i < mp[start].size(); ++i) {
        string s = mp[start][i];
        path.push_back(s);
        output(s, end);
        path.pop_back();
      }
    }
    return 0;
  }

  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    dict.insert(start);
    dict.insert(end);
    cur = &a; next = &b;
    //dump("###")
    cur->insert(start);
    //dump("###")

    unordered_set<string>::iterator it;
    while (true) {
      for (it = cur->begin(); it != cur->end(); ++it)
        dict.erase(*it);
      findNext(dict);
      
      //dump("####")
      //for (it = cur->begin(); it != cur->end(); ++it)
        //cout << *it << ' ';
      //cout << endl;
      //for (it = next->begin(); it != next->end(); ++it)
        //cout << *it << ' ';
      //cout << endl;
      //dump("####")

      if (next->size() == 0) return ans;

      if (next->count(end)) {
        path.push_back(start);
        output(start, end);
        //for (int i = 0; i < ans.size(); ++i)
          //reverse(ans[i].begin(), ans[i].end());
        return ans;
      }

      unordered_set<string> *tmp = cur;
      cur = next;
      next = tmp;
      next->clear();
    }
    return ans;
  }
};


int main() {
  Solution s;
  string start, end;
  unordered_set<string> dict;
  start = "hit";
  end = "cog";
  dict.insert("hot");
  dict.insert("dot");
  dict.insert("dog");
  dict.insert("lot");
  dict.insert("log");
  vector<vector<string> > ans;
  ans = s.findLadders(start, end, dict);
  dump(ans.size());
  for (int i = 0; i < ans.size(); ++i)
    out(ans[i]);
  return 0;
}
