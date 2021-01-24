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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  pair<int, TreeNode*> dfs(TreeNode *node, int k) {
    if (node == NULL) return make_pair(0, node);
    if (k == 1) {
      while (node->left != NULL) node = node->left;
      return make_pair(1, node);
    }

    int size = 1;
    auto ans_l = dfs(node->left, k);
    if (ans_l.second != NULL) return make_pair(0, ans_l.second);
    size += ans_l.first;
    if (size == k) return make_pair(size, node);

    auto ans_r = dfs(node->right, k-size);
    if (ans_r.second != NULL) return make_pair(0, ans_r.second);
    size += ans_r.first;

    return make_pair(size, (TreeNode*)NULL);
  }

  int kthSmallest(TreeNode* root, int k) {
    auto ans = dfs(root, k);
    return ans.second->val; 
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
