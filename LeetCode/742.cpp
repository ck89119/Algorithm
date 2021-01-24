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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  map<int, pair<int, int>> leaf_dis;
  
  pair<int, int> dfs(TreeNode *node) {
    if (node == NULL) return make_pair(INF, -1);

    int val = node->val;
    if (node->left == NULL && node->right == NULL) leaf_dis[val] = make_pair(0, val);
    auto l = dfs(node->left);
    auto r = dfs(node->right);
    if (l.first < r.first) {
      return leaf_dis[val] = make_pair(l.first+1, l.second); 
    }
    return leaf_dis[val] = make_pair(r.first+1, r.second);
  }

  int closest(TreeNode *node, TreeNode *pre) {
    if (node == NULL) return 0;
    
    if (pre != NULL) {
      int val = node->val;
      int pre_val = pre->val;
      if (leaf_dis[val].first > leaf_dis[pre_val].first + 1) {
        leaf_dis[val] = make_pair(leaf_dis[pre_val].first+1, leaf_dis[pre_val].second);
      }
    }
    closest(node->left, node);
    closest(node->right, node);
    return 0;
  }

  int findClosestLeaf(TreeNode* root, int k) {
    dfs(root);
    closest(root, NULL);
    return leaf_dis[k];
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
