# -*- coding: utf-8 -*-

#####################################################################
# File Name:  Create_Maximum_Number.py
# Author: shenming
# Created Time: Tue Jan 28 13:15:50 2020
#####################################################################

import os
import sys

class Solution():
    # nums1 = [3, 4, 6, 5]
    # nums2 = [9, 1, 2, 5, 8, 3]
    def maxNumber(self, nums1, nums2, k):
        def maximize(nums, length):
            dp, i = {length:nums}, 0
            while (length):
                while (i+1 < length and nums[i] >= nums[i+1]): i+=1
                nums, length = nums[:i] + nums[i+1:], length-1
                dp[length] = nums
                if i>0: i-=1
            return dp
        m,n,result = len(nums1), len(nums2),[]
        dp1, dp2 = maximize(nums1, m), maximize(nums2, n)
        print(dp1)
        print(dp2)
        for i in range(min(m+1,k+1)):
            if k-i not in dp2: continue
            result = max(result,[max(dp1[i],dp2[k-i]).pop(0) for _ in range(k)])
        return result

if __name__ == "__main__":
    s = Solution()
    nums1 = [3, 4, 6, 5]
    # nums2 = [9, 1, 2, 5, 8, 3]
    nums2 = [9, 3, 5, 5, 1, 2]
    nums = s.maxNumber(nums1, nums2, 5)
    print(nums)
