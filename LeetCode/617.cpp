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
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return NULL;
    
    TreeNode *node;
    if (t1 == NULL) {
      node = new TreeNode(t2->val);
      node->left = mergeTrees(NULL, t2->left);
      node->right = mergeTrees(NULL, t2->right);
    } else if (t2 == NULL) {
      node = new TreeNode(t1->val);
      node->left = mergeTrees(t1->left, NULL);
      node->right = mergeTrees(t1->right, NULL);
    } else {
      node = new TreeNode(t1->val + t2->val);
      node->left = mergeTrees(t1->left, t2->left);
      node->right = mergeTrees(t1->right, t2->right);
    }
    return node;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
