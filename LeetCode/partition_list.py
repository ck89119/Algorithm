#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param x, an integer
    # @return a ListNode
    def partition(self, head, x):
      node = ListNode(-1)
      node.next = head
      head = node
      insert_node = head
      while insert_node.next != None and insert_node.next.val < x:
        insert_node = insert_node.next
      pre = insert_node
      cur = insert_node.next
      while cur != None:
        while cur != None and cur.val >= x:
          pre = cur
          cur = cur.next
        if cur == None: break
        pre.next = cur.next
        cur.next = insert_node.next
        insert_node.next = cur
        insert_node = insert_node.next
        cur = pre.next
      return head.next

ss = Solution()
node1 = ListNode(1)
node2 = ListNode(4)
node3 = ListNode(3)
node4 = ListNode(2)
node5 = ListNode(5)
node6 = ListNode(2)
node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5
node5.next = node6
head = ss.partition(node1, 3)
while head != None:
  print head.val
  head = head.next


