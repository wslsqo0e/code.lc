# -*- coding: utf-8 -*-

#####################################################################
# File Name:  canJump.py
# Author: shenming
# Created Time: Mon Jan 27 18:35:50 2020
#####################################################################

import os
import sys
from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        current_valid_index = len(nums) - 1

        for index in range(len(nums)-1, -1, -1):
            if (nums[index] + index >= current_valid_index):
                if (index ==0):
                    return True
                else:
                    current_valid_index = index
        return False

if __name__ == "__main__":
    s= Solution()
    print(s.canJump([2, 3, 1, 1, 4]))
    pass
