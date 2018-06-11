# -*- encoding: utf-8 -*-

class Solution:
    def isPalindrome(self, x):
        if x < 0 or (x != 0 and x % 10 == 0):
            # x必须非负并且末位不为0
            return False
        sum = 0
        # 将x反转
        while x > sum:
            sum = sum * 10 + x % 10
            x = x // 10

        return (x == sum or x == sum // 10)


x = 12321
f = Solution()
print(f.isPalindrome(x))
