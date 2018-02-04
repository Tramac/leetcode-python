# -*- encoding: utf-8 -*-

class Solution:
    def longestCommonPrefix(self, strs):
        # 本题参考的讨论中答案,巧用了zip()和set()函数.
        if not strs:
            return ""

        print(zip(*strs))
        for i, letter_group in enumerate(zip(*strs)):
            if len(set(letter_group)) > 1:
                return strs[0][:i]
        else:
            return min(strs)


strs = ["abc", "abcd", "abd"]
f = Solution()
lcp = f.longestCommonPrefix(strs)
print(lcp)
