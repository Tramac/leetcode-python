# -*- encoding: utf-8 -*-

class ListNode:
    def __init__(self, key):
        self.key = key
        self.next = None


class LinkList:
    def __init__(self):
        self.head = None
        self.size = 0

    def insert(self, key):
        x = ListNode(key)
        x.next = self.head
        self.head = x
        self.size += 1

    def show(self):
        x = self.head
        while x is not None:
            print(x.key)
            x = x.next


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :param l1:
        :param l2:
        :return:
        """
        l3 = LinkList()
        x1 = l1.head
        x2 = l2.head
        flag = 0
        while x1 or x2:
            x3 = 0
            if x1:
                x3 += x1.key
                x1 = x1.next
            if x2:
                x3 += x2.key
                x2 = x2.next
            l3.insert(x3 % 10 + flag)
            flag = x3 / 10
        return l3


l1 = LinkList()
l2 = LinkList()
l1.insert(2)
l1.insert(4)
l1.insert(3)
l2.insert(5)
l2.insert(6)
l2.insert(4)
f = Solution()
l3 = f.addTwoNumbers(l1, l2)
l3.show()
