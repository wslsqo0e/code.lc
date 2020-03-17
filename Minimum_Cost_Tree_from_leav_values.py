# -*- coding: utf-8 -*-

#####################################################################
# File Name:  Minimum_Cost_Tree_from_leav_values.py
# Author: shenming
# Created Time: Sun Jan 26 20:04:33 2020
# reference: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/478708/RZ-Summary-of-all-the-solutions-I-have-learned-from-Discuss-in-Python
#####################################################################

import os
import sys

# Top down code with memorization
# class Solution_ref_1:
#     def mctFromLeafValues(self, arr: list[int]) -> int:
#         return self.helper(arr, 0, len(arr) - 1, {})
#
#     def helper(self, arr, l, r, cache):
#         if (l, r) in cache:
#             return cache[(l, r)]
#         if l>= r:
#             return 0
#         res = float('inf')
#         for i in range(l, r):
#             rootVal = max(arr[l:i+1]) * max(arr[i+1:r+1])
#             res = min(res, rootVal + self.helper(arr, l, i, cache) + self.helper(arr, i+1, r, cache))
#         cache[(l, r)] = res
#         return res


class Solution:
    def mctFromLeafValues(self, arr) -> int:
        stack = [float('inf')]
        res = 0
        for num in arr:
            while stack and stack[-1] <= num:
                cur = stack.pop()
                if stack:
                    res += cur * min(stack[-1], num)
            stack.append(num)
        while len(stack) > 2:
            res += stack.pop() * stack[-1]
        return res

if __name__ == "__main__":
    s = Solution()
    print(s.mctFromLeafValues([6, 3, 7, 1, 2]))
