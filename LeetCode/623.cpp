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
  int get_nth_level_node(TreeNode *node, int lvl, vector<TreeNode*> &ans) {
    if (node == NULL) return 0;

    if (lvl == 1) {
      ans.push_back(node);
      return 0;
    }
    get_nth_level_node(node->left, lvl - 1, ans);  
    get_nth_level_node(node->right, lvl - 1, ans);  
    return 0;
  }

  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      TreeNode *node = new TreeNode(v);
      node->left = root;
      return node;
    }
    
    vector<TreeNode*> nodes;
    get_nth_level_node(root, d-1, nodes);
    for (auto node: nodes) {
      TreeNode* new_node;
      new_node = new TreeNode(v);
      new_node->left = node->left;
      node->left = new_node;
      new_node = new TreeNode(v);
      new_node->right = node->right;
      node->right = new_node;
    }
    return root;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
