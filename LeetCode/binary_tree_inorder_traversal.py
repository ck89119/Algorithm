#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def inorderTraversal(self, root):
      if root == None: return []
      ans = []
      ans.extend(self.inorderTraversal(root.left))
      ans.append(root.val)
      ans.extend(self.inorderTraversal(root.right))
      return ans
