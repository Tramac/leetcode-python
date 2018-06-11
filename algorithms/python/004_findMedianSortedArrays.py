# -*- encoding: utf-8 -*-

class Solution:
    def findMedianSorteArrays(self, nums1, nums2):
        """
        :param nums1:
        :param nums2:
        :return:
        """
        # 主要问题是两个数组中元素数量的奇偶性, 分位数的应用,递归的应用
        l = len(nums1) + len(nums2)
        if l % 2 == 1:
            # 如果元素个数和为奇数
            return self.kth(nums1, nums2, l // 2)
        else:
            return (self.kth(nums1, nums2, l // 2) + self.kth(nums1, nums2, l // 2 - 1)) / 2.

    def kth(self, a, b, k):
        # 求解k分位数,算法导论习题9.3-6
        if not a:
            return b[k]
        if not b:
            return a[k]
        ia, ib = len(a) // 2, len(b) // 2
        ma, mb = a[ia], b[ib]

        # 当k大于a,b的中位数索引之和
        if ia + ib < k:
            # 如果ma>mb,那么b的前半部分肯定不会包含k
            if ma > mb:
                return self.kth(a, b[ib + 1:], k - ib - 1)
            else:
                return self.kth(a[ia + 1:], b, k - ia - 1)
        else:
            # 如果ma>mb,那么a的后半部分肯定不会包含k
            if ma > mb:
                return self.kth(a[: ia], b, k)
            else:
                return self.kth(a, b[: ib], k)


nums1 = [1, 2]
nums2 = [3, 4]
f = Solution()
median = f.findMedianSorteArrays(nums1, nums2)
print(median)
