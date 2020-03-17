/*************************************************************************
> File Name:  brick-wall.cpp
> Author: shenming
> Created Time: Tue Feb  4 00:50:02 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int Height = wall.size();
        map<int, int> mm;
        for (auto& vv : wall) {
            int sum = 0;
            for (int i = 0; i < (int)vv.size() - 1; i++) {
                sum += vv[i];
                mm[sum]++;
            }
        }
        int max_height = 0;
        for (auto p : mm) {
            if (p.second > max_height) {
                max_height = p.second;
            }
        }
        return Height - max_height;
    }
};
