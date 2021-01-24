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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool check(int s, int h, TreeNode *root) {
    TreeNode *cur = root;
    for (int i = h-1; i >= 0; --i) {
      int bit = s & (1 << i);
      if (bit) cur = cur->left;
      else cur = cur->right;
    }
    return cur != NULL;
  } 

  int get_h(TreeNode *root) {
    TreeNode* cur = root;
    int h = 0;
    while (cur != NULL) h++, cur = cur->left;
    return h - 1;
  }
  
  int countNodes(TreeNode* root) {
    if (root == NULL) return 0;

    int h = get_h(root);
    int ans = (1 << (h + 1)) - 1;
    if (check(0)) return ans;

    int l = -1, r = (1 << h) - 1;
    while (l + 1 < r) {
      int m = (l + r) >> 1;
      if (check(m, h, root)) r = m;
      else l = m;
    }
    return ans - r;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  return 0;
}
