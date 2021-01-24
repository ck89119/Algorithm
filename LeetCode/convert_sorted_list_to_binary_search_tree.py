#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def construct(self, head, l):
      if l == 0: return None
      count = 0
      node = head
      while count < l/2:
        node = node.next
        count += 1

      root = TreeNode(node.val)
      root.left = self.construct(head, count)
      root.right = self.construct(node.next, l - count - 1)
      return root
    
    def sortedListToBST(self, head):
      if head == None: return None
      l = 0
      node = head
      while node != None:
        l += 1
        node = node.next
      return self.construct(head, l)


