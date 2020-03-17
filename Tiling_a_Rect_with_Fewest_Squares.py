# -*- coding: utf-8 -*-

#####################################################################
# File Name:  Tiling_a_Rect_with_Fewest_Squares.py
# Author: shenming
# Created Time: Wed Jan 29 20:05:45 2020
#####################################################################

import os
import sys

class Solution:
    def __init__(self):
        pass

    def tilingRectangle(self, width, height):
        total_area = width * height
        dp = [-1 for i in range(total_area +1)]
        dp[0] = 0
        for i in range(1, total_area + 1):
            # try each possible k
            dp[i] = 1 + min(dp[i - k**2] for k in range(1, int(i ** 0.5) + 1))
        print(dp)
        self.res = total_area


if __name__ == "__main__":
    s = Solution();
    s.tilingRectangle(11, 13)
