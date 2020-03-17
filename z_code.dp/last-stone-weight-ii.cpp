/*************************************************************************
> File Name:  last-stone-weight-ii.cpp
> Author: shenming
> Created Time: Wed Feb  5 10:00:31 2020
************************************************************************/
// https://leetcode.com/problems/last-stone-weight-ii/
// not done

#include "common_lc.h"


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int N = stones.size();
        if (N == 1) {
            return stones[0];
        }
        sort(stones.begin(), stones.end());
        vector<int> vv;
        for (int i = 0; i < N-2; i++) {
            vv.push_back(stones[i]);
        }
        vv.push_back(stones[N-1] - stones[N-2]);
        return lastStoneWeightII(vv);
    }
};

int main()
{
    Solution s;

    return 0;
}
