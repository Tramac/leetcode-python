# -*- encoding: utf-8 -*-

class Solution:
    def threeSumClosest(self, nums, target):
        """
        :param nums:
        :param target:
        :return:
        """
        nums.sort()
        closest = float('Inf')
        for i in xrange(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                if sum == target:
                    return sum
                if abs(sum - target) < abs(closest - target):
                    closest = sum
                if sum < target:
                    l += 1
                elif sum > target:
                    r -= 1

        return closest


nums = [-1, 2, 1, -4]
target = 1
f = Solution()
closest = f.threeSumClosest(nums, target)
print(closest)
