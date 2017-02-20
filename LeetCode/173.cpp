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
 * Definition for binary tree
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

class BSTIterator {
 public:
  struct NewNode {
    TreeNode *node;
    NewNode *next; 
    NewNode(TreeNode *_node): node(_node), next(NULL) {}
  };
  NewNode *pre, *it;

  BSTIterator(TreeNode *root) {
    pre = new NewNode(new TreeNode(0));
    it = pre;
    construct(root);
  }

  int construct(TreeNode *cur) {
    if (cur == NULL) return 0;
  
    NewNode *node = new NewNode(cur);
    construct(cur->left);
    if (pre->next == NULL) {
      pre->next = node;
    }
    pre = node;
    construct(cur->right);
    return 0;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return it->next != NULL;
  }

  /** @return the next smallest number */
  int next() {
    it = it->next;
    return it->node->val;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
#ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  TreeNode *root = new TreeNode(1);
  BSTIterator i = BSTIterator(root);
  while (i.hasNext()) cout << i.next() << ' ';
  cout << endl;
  return 0;
}

