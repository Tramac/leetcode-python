# -*- encoding: utf-8 -*-

class Solution:
    def maxArea(self, height):
        """
        :param height:
        :return:
        """
        # 思路一.双循环,遍历所有可能的两两组合,时间复杂度太高O(n2)
        # 思路二.需要证明
        MAX = 0
        x = len(height) - 1
        y = 0
        while x != y:
            if height[x] > height[y]:
                area = height[y] * (x - y)
                y += 1
            else:
                area = height[x] * (x - y)
                x -= 1
            MAX = max(MAX, area)

        return MAX
