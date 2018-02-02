# -*- encoding: utf-8 -*-

# 核心思想是什么?
class Solution:
    def lengthOfLongestSubstring(self, s):
        start = maxLenght = 0
        usedChar = {}  # 学会字典的运用,关键字用来存储索引

        for i in range(len(s)):
            if s[i] in usedChar and start <= usedChar[s[i]]:  # 不明白start的意义以及它的更新策略是什么?
                start = usedChar[s[i]] + 1
            else:
                maxLenght = max(maxLenght, i - start + 1)

            usedChar[s[i]] = i  # 这种字典的应用就是哈希表的思想,将字符串中的元素映射到一个位置!
                                # python中的字典就是选用的哈希表的数据结构.所以如果算法用到哈希表,
                                # 那么直接创建字典即可.

        return maxLenght


s = "pwwkew"
f = Solution()
maxLength = f.lengthOfLongestSubstring(s)
print(maxLength)
