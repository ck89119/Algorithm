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
  int find_max(int l, int r, const vector<int> &nums) {
    int max_v = -INF;
    int max_i = -1;
    for (int i = l; i <= r; ++i) {
      if (nums[i] > max_v) {
        max_v = nums[i];
        max_i = i;
      }
    }
    return max_i;
  }

  TreeNode* build(int l, int r, const vector<int> &nums) {
    if (l > r) return NULL;
    int m = find_max(l, r, nums);
    TreeNode *root = new TreeNode(nums[m]);
    root->left = build(l, m-1, nums); 
    root->right = build(m+1, r, nums);
    return root;
  }

  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(0, nums.size()-1, nums);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  
  return 0;
}
