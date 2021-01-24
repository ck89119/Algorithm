#!/usr/bin/python
class ListNode:
  def __init__(self, key, value):
    self.key = key
    self.value = value
    self.next = None
    self.pre = None

class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
      self.cap = capacity
      self.n = 0
      self.head = ListNode(-1, -1)
      self.tail = self.head

    # @return an integer
    def get(self, key):
      node = self.head.next
      while node != None and node.key != key:
        node = node.next
      if node == None:
        return -1
      else:
        if node == self.head.next: return node.value
        if node == self.tail:
          node.pre.next = None
          self.tail = node.pre
          node.pre = self.head
          node.next = self.head.next
          self.head.next.pre = node
          self.head.next = node
        else:
          node.pre.next = node.next
          node.next.pre = node.pre
          node.next = self.head.next
          self.head.next.pre = node
          node.pre = self.head
          self.head.next = node
      return node.value

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
      if self.get(key) == -1:
        self.n += 1
        node = ListNode(key, value)
        if self.n == 1:
          self.head.next = node
          node.pre = self.head
          self.tail = node
        else:
          self.head.next.pre = node
          node.next = self.head.next
          self.head.next = node
          node.pre = self.head
        if self.n > self.cap:
          self.n -= 1
          self.tail.pre.next = None
          self.tail = self.tail.pre
      else:
        node = self.head.next
        while node.key != key:
          node = node.next
        node.value = value

ss = LRUCache(2)
ss.set(2, 1)
print ss.get(2)
