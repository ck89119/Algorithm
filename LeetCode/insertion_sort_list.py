#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None


class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
      if head == None or head.next == None: return head
      node = ListNode(-1)
      node.next = head
      head = node
      cur = head.next
      while cur.next != None and cur.next.val >= cur.val:
        cur = cur.next
      tmp = cur
      cur = cur.next
      tmp.next = None

      while cur != None:
        node = head
        while node.next != None and node.next.val < cur.val:
          node = node.next
        tmp = cur
        cur = cur.next
        tmp.next = node.next
        node.next = tmp
      return head.next

ss = Solution()
node = ListNode(2)
node1 = ListNode(1)
node.next = node1
head = node

head = ss.insertionSortList(head)
while head != None:
  print head.val
  head = head.next
        
