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

string int2str(int x) {
  ostringstream os;
  os << x;
  return os.str();
}

class Solution {
 public:
  int dfs(TreeNode *node, string s, vector<string> &ans) {
    s += "->";
    s += int2str(node->val);
    if (node->left == NULL && node->right == NULL) {
      ans.push_back(s.substr(2));
      return 0;
    }
    if (node->left) dfs(node->left, s, ans);
    if (node->right) dfs(node->right, s, ans);
    return 0;
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if (root == NULL) return ans;

    string s = "";
    dfs(root, s, ans);
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
