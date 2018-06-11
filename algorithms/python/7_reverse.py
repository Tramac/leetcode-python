# -*- encoding: utf-8 -*-

class Solution:
    def reverse(self, x):
        """
        :param x:
        :return:
        """
        # 自己写的版本并不是在二进制的角度来写,并且也没处理负数情况
        # if x // 10 == 0:
        #     return x
        # x_reverse = 0
        # while x // 10 != 0:
        #     mod = x % 10
        #     x = x // 10
        #     x_reverse = x_reverse * 10 + mod
        # x_reverse = x_reverse * 10 + x
        #
        # return x_reverse
        sign = cmp(x, 0)  # 获取符号
        r = int(str(abs(x))[::-1])  # 将数字转换为字符串然后反向,之后再转回数字
        return sign * r * (r < 2 ** 31)  # 判断条件将r限制在32bit内


x = 123
f = Solution()
x_reverse = f.reverse(x)
print(x_reverse)
