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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generate(int start, int end) {
      vector<TreeNode *> ans;
      if (start > end) {
        ans.push_back(NULL);
        return ans;
      }
      
      int i, j, k;
      for (i = start; i <= end; ++i) {
        vector<TreeNode *> l = generate(start, i-1);
        vector<TreeNode *> r = generate(i+1, end);
        if (l.size() == 0) l.push_back(NULL);
        if (r.size() == 0) r.push_back(NULL);
        for (j = 0; j < l.size(); ++j)
          for (k = 0; k < r.size(); ++k) {
            TreeNode *node = new TreeNode(i);
            node->left = l[j]; node->right = r[k];
            ans.push_back(node);
          }
      }
      return ans;
    }

    vector<TreeNode *> generateTrees(int n) {
      if (n == 0) return generate(1, 0);
      else return generate(1, n);
    }
};

int main() {
  //fin; fout;
  Solution s;
  while (1) {
    int n;
    cin >> n;
    out(s.generateTrees(n));
  }
  return 0;
}
