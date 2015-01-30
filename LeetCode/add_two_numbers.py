#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
      node1 = l1
      node2 = l2
      while node1 != None:
        if node2 == None: break
        node1.val += node2.val
        if node1.next == None and node2.next != None:
          node1.next = node2.next
          node2.next = None
        node1 = node1.next
        node2 = node2.next
      node1 = l1
      carry = 0
      while node1 != None:
        node1.val += carry
        carry = node1.val / 10
        node1.val %= 10
        if node1.next == None and carry != 0:
          node = ListNode(carry)
          carry = 0
          node1.next = node
        node1 = node1.next
      return l1

s = Solution()
a = ListNode(5)
b = ListNode(5)
l = s.addTwoNumbers(a, b)
while l != None:
  print l.val
  l = l.next
