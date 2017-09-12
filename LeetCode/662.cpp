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
  int widthOfBinaryTree(TreeNode* root) {
    int ans = 0;
    vector<pair<TreeNode*, int>> v[2];
    v[0].push_back(make_pair(root, 1));
    for (int c = 0; v[c].size(); c ^= 1) {
      int base = v[c][0].second - 1;
      ans = max(ans, v[c][v[c].size()-1].second - base);

      v[1-c].clear();
      for (auto p: v[c]) {
        TreeNode *node = p.first;
        int no = p.second - base;
        if (node->left != NULL) v[1-c].push_back(make_pair(node->left, no * 2));
        if (node->right != NULL) v[1-c].push_back(make_pair(node->right, no * 2 + 1));
      } 
    } 
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
