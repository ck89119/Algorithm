#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
      if head == None: return None
      if k == 1: return head
      node_list = []
      node = ListNode(-1)
      node.next = head
      head = node
      while node != None:
        node_list.append(node)
        node = node.next
      node_list.append(None)
      n = len(node_list) - 2
      if k > n: return head.next
      base = 0
      while base + k <= n:
        count = k
        while count > 1:
          node_list[base+count].next = node_list[base+count-1]
          count -= 1
        base += k
      node_list[0].next = node_list[k]
      base = 0
      while base+k+k <= n:
        node_list[base+1].next = node_list[base+k+k]
        base += k
      node_list[base+1].next = node_list[base+k+1]
      return head.next

ss = Solution()
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)
node5 = ListNode(5)
node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5
head = ss.reverseKGroup(node1, 6)
while head != None:
  print head.val
  head = head.next

      
