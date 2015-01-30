#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def zigzagLevelOrder(self, root):
      if root == None: return []
      ans = []
      queue = []
      height = []
      queue.append(root)
      height.append(1)
      while len(queue) > 0:
        item = queue[0]
        queue.pop(0)
        h = height[0]
        height.pop(0)
        if len(ans) < h:
          ans.append([])
        ans[-1].append(item.val)
        
        if item.left != None:
          queue.append(item.left)
          height.append(h+1)
        if item.right != None:
          queue.append(item.right)
          height.append(h+1)
      for i in range(0, len(ans)):
        if i % 2 == 1:
          ans[i].reverse()

      return ans
