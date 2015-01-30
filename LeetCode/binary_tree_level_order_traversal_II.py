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
    def levelOrderBottom(self, root):
      if root == None: return []    
      ans = []
      queue = []
      height = []
      queue.append(root)
      height.append(0)
      while len(queue) > 0:
        item = queue[0]
        queue.pop(0)
        h = height[0]
        height.pop(0)
        if len(ans) <= h:
          tmp = []
          tmp.append(item.val)
          ans.append(tmp)
        else:
          ans[h].append(item.val)
        if item.left != None:
          queue.append(item.left)
          height.append(h+1)
        if item.right != None:
          queue.append(item.right)
          height.append(h+1)
      ans.reverse()
      return ans
