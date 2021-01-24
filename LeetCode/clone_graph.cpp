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
#include <cstring>
#include <cstdlib>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      if (node == NULL) return NULL;
      queue<UndirectedGraphNode*> q;
      map<int, UndirectedGraphNode*> m;
      UndirectedGraphNode *ans;
      ans = new UndirectedGraphNode(node->label);
      m[node->label] = ans;
      q.push(node);
      while (!q.empty()) {
        UndirectedGraphNode *item = q.front(); q.pop();
        UndirectedGraphNode *tmp = m[item->label];
        int i;
        for (i = 0; i < item->neighbors.size(); ++i) {
          int label = item->neighbors[i]->label;
          if (m.count(label) == 0) {
            UndirectedGraphNode *t = new UndirectedGraphNode(label);
            m[label] = t;
            tmp->neighbors.push_back(t);
            q.push(item->neighbors[i]);
          } else {
            tmp->neighbors.push_back(m[label]);
          }
        }
      }
      return ans;
    }
};

int main() {
  //fin; fout;
  
  return 0;
}
