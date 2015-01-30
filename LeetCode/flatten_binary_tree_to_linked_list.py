#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return nothing, do it in place
    def pre(self, root):
      if root == None: return
      self.pre_list.append(root)
      self.pre(root.left)
      self.pre(root.right)

    def flatten(self, root):
      if root == None: return
      self.pre_list = []
      self.pre(root)
      for i in range(0, len(self.pre_list)-1):
        self.pre_list[i].left = None
        self.pre_list[i].right = self.pre_list[i+1]

