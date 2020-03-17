/*************************************************************************
> File Name:  partition-equal-subset-sum.cpp
> Author: shenming
> Created Time: Fri Feb  7 01:31:20 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j]  after ith num, 和为 j 是否能实现
    // dp[i][j] = dp[i-1][j] | dp[i-1][j-num[i]]
    bool canPartition(vector<int>& nums) {
        int ss = accumulate(nums.begin(), nums.end(), 0);
        if (ss&1) {
            return false;
        }
        ss = ss/2;
        vector<bool> dp(ss+1);
        dp[0] = 1;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int k = ss; k >= nums[i]; k--) {
                dp[k] = dp[k] | dp[k-nums[i]];
            }
            if (dp[ss]) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    return 0;
}
