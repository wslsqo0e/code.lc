# -*- coding: utf-8 -*-

#####################################################################
# File Name:  OutofBoundaryPaths.py
# Author: shenming
# Created Time: Mon Jan 27 13:24:12 2020
#####################################################################

import os
import sys
from functools import lru_cache

class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        @lru_cache(None)
        def dp(i, j, N):
            if i < 0 or i >= m or j < 0 or j >= n:
                return int(N >= 0)
            elif N < 0:
                return 0
            res = 0
            for k in (1, -1):
                res += dp(i + k, j, N - 1) + dp(i, j + k, N - 1)
            return res

        return dp(i, j, N) % (10 ** 9 + 7)


if __name__ == "__main__":
    pass
