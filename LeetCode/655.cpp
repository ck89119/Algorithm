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
  int get_h(TreeNode *root) {
    if (root == NULL) return 0;
    return max(get_h(root->left), get_h(root->right)) + 1;
  }

  int dfs(TreeNode *node, int dep, int index, int delta, vector<vector<string>> &ans) {
    if (node == NULL) return 0;
    ans[dep][index-1] = int2str(node->val);
    dfs(node->left, dep+1, index-delta, delta>>1, ans);
    dfs(node->right, dep+1, index+delta, delta>>1, ans);
    return 0;
  }

  string int2str(int n) {
    ostringstream os;
    os << n;
    return os.str();
  }

  vector<vector<string>> printTree(TreeNode* root) {
    if (root == NULL) vector<vector<string>>();
    int h = get_h(root);
    vector<vector<string>> ans = vector<vector<string>>(h, vector<string>((1<<h)-1, ""));
    dfs(root, 0, 1<<(h-1), 1<<(h-2), ans);
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
