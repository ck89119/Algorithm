#!/usr/bin/python

# Definition for a  binary tree node
class TreeNode:
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a boolean
    def hasPathSum(self, root, sum):
      if root == None: return False

      if (root.left == None and root.right == None and root.val == sum):
        return True
      
      ans1 = self.hasPathSum(root.left, sum - root.val)
      if ans1 == True: return True

      ans2 = self.hasPathSum(root.right, sum - root.val)
      return ans2

t = TreeNode(2)
s = Solution()
print s.hasPathSum(t, 1)
