# -*- coding: utf-8 -*-

#####################################################################
# File Name:  Combination_sum.py
# Author: shenming
# Created Time: Wed Jan 29 21:11:19 2020
#####################################################################

import os
import sys

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates:
            return []

        ret = []

        def fn(nums, tmp):
            if sum(tmp) > target:
                return False
            elif sum(tmp) == target:
                ret.append(tmp)
                return True
            else:


if __name__ == "__main__":
    pass
