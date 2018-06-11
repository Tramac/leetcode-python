# -*- encoding: utf-8 -*-

class Solution:
    def letterCombinations(self, digits):
        """
        :param digits:
        :return:
        """
        if ' ' == digits:
            return []
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        # return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], dicits, [' '])
        ret = [' ']
        for c in digits:
            tmp = []
            for y in ret:  # ret中保存的是前面数字的组合,重要
                for x in kvmaps[c]:
                    tmp.append(y + x)

            ret = tmp

        return ret


digits = '23'
f = Solution()
out = f.letterCombinations(digits)
print(out)
