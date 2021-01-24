#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
      if root == None: return 
      q = []
      head = 0
      q.append((root, 0))
      while head < len(q):
        (node, h) = q[head]
        head += 1
        
        if node.left != None:
          q.append((node.left, h+1))
        if node.right != None:
          q.append((node.right, h+1))
      
      (pre_node, pre_h) = q[0]
      i = 1
      while i < len(q):
        (node, h) = q[i]
        if h == pre_h:
          pre_node.next = node
        else: 
          pre_node.next = None
        (pre_node, pre_h) = (node, h)
        i += 1
          
