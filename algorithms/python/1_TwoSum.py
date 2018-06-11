# -*- encoding: utf-8 -*-

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 本题主要思路:用一个字典存储target与nums中元素的差值以及对应的索引(作为关键字),
        # 然后判断nums中是否存在与字典中相同的元素,若相同,那么该位置的两个元素和就为target
        if len(nums) <= 1:
            return False
        buff_dict = {}
        for i in range(len(nums)):
            if nums[i] in buff_dict:
                return [buff_dict[nums[i]], i]
            else:
                buff_dict[target - nums[i]] = i


nums = [2, 7, 11, 15]
target = 9
f = Solution()
ans = f.twoSum(nums, target)
print(ans)
