# -*- coding: utf-8 -*-

#####################################################################
# File Name:  racecar.py
# Author: shenming
# Created Time: Sun Jan 26 10:29:12 2020
#####################################################################

import os
import sys

class Solution:
    # why BFS
    # BFS could find minimum value
    def racecar(self, target:int) ->int:
        def bfs():
            from collections import deque
            Q = deque([(0,1,0)])
            seen = {(0,1)}
            if target==0:return 0
            while True:
                p, s, d = Q.popleft()
                for action in [True, False]:
                    if action:
                        this_p = p + s
                        s *= 2
                        if this_p==target:return d+1
                        if (this_p, s) not in seen:
                            seen.add((this_p, s))
                            Q.append((this_p, s, d+1))
                    else:
                        if s>0:s=-1
                        else s=1
                        if (p, s) not in seen:
                            seen.add((p, s))
                            Q.append((p, s, d+1))


if __name__ == "__main__":
    pass
