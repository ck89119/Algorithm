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
      root.next = None
      queue = []
      queue.append(root)
      while len(queue) > 0:
        item = queue[0]
        queue.pop(0)
        l = item.left
        r = item.right
        if l != None:
          l.next = r
          queue.append(l)
        if r != None:
          r.next = None
          if item.next != None:
            r.next = item.next.left
          queue.append(r)
      return 
