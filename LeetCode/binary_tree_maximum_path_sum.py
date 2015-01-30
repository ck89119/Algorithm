#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def max_root_to_leaf(self, root):
      if root == None: return 0
      ans = root.val
      ans += max(self.max_root_to_leaf(root.left),
                 self.max_root_to_leaf(root.right))
      return ans
    
    def maxPathSum(self, root):
      if root == None: return 0
      l = self.max_root_to_leaf(root.left)
      r = self.max_root_to_leaf(root.right)
      ans = l + r + root.val
      
