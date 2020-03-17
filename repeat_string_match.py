# -*- coding: utf-8 -*-

#####################################################################
# File Name:  repeat_string_match.py
# Author: shenming
# Created Time: Sun Jan 26 23:42:19 2020
#####################################################################

import os
import sys

from collections import deque

class Solution:
    def repeatStringMatch(self, A: str, B: str) -> int:
        aLen = len(A)
        qA = deque(A)

        aRots = 0
        while aRots < aLen:
            for c1, c2 in zip(qA, B):
                if c1 != c2:
                    break
            else:
                break
            aRots += 1
            qA.rotate(-1)
        else:
            return -1
        bLen = len(B)
        if aLen >= bLen:
            if aRots <= (aLen - bLen):
                return 1
            else:
                return 2
        else:
            for c in B:
                if c != qA[0]:
                    return -1
                qA.rotate(-1)
            res, r = divmod(bLen - aLen + aRots, aLen)
            if (r > 0):
                res += 1
            return res + 1

if __name__ == "__main__":
    s = Solution()
    print(s.repeatStringMatch("aabaa", "aaab"))
