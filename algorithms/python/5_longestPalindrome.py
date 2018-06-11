# -*- encoding: utf-8 -*-

class Solution:
    def longestPalindrome(self, s):
        """
        :param s:
        :return:
        """
        start = end = 0
        maxLength = 0
        diff_char = {}  # 本题关键仍是哈希表的应用
        for i in range(len(s)):
            if s[i] in diff_char:
                # 判断新重复的两个字符间的距离是否大于已有的重复字符串距离,如果大于再做更改
                if (i - diff_char[s[i]] + 1) > maxLength:
                    maxLength = i - diff_char[s[i]] + 1
                    start = diff_char[s[i]]
                    end = i
            else:
                diff_char[s[i]] = i

        return s[start: end + 1]


s = "babad"
f = Solution()
l = f.longestPalindrome(s)
print(l)
