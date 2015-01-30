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
    def postorderTraversal(self, root):
      if root == None: return []
      
      ans = []
      if root.left != None:
        ans.extend(self.postorderTraversal(root.left))
      if root.right != None:
        ans.extend(self.postorderTraversal(root.right))
      ans.append(root.val)
      return ans
