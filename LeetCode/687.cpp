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
  int ans;
  int dfs(TreeNode* node) {
    if (node == NULL) return 0;
    int l = dfs(node->left);
    int r = dfs(node->right);
    int cnt = 1;
    int length = 1;
    if (node->left != NULL && node->val == node->left->val) {
      cnt += l;
      length = max(length, l + 1);
    }
    if (node->right != NULL && node->val == node->right->val) {
      cnt += r;
      length = max(length, r + 1);
    }
    ans = max(ans, cnt);
    return length;
  }

  int longestUnivaluePath(TreeNode* root) {
    if (root == NULL) return 0;
    ans = 0;
    dfs(root);
    return ans - 1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
