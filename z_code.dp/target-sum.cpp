/*************************************************************************
> File Name:  target-sum.cpp
> Author: shenming
> Created Time: Thu Feb  6 15:30:25 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    void update_dp(vector<int>& dp1, vector<int>& dp2, int N, int num) {
        for (int i = 0; i <= N; i++) {
            dp2[i] = (i - num >= 0 ? dp1[i-num]:0) + (i+num <=N ? dp1[i+num]:0);
        }
    }
    // dp[i][j]  after ith num, 和为j-1000的数量
    // dp[i][j]  dp[i-1][j-nums[i-1]] + dp[i-1][j+nums[i-1]]
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000 || S < -1000) {
            return 0;
        }
        vector<int> dp1(2001, 0);
        vector<int> dp2(2001, 0);
        dp1[1000] = 1;
        int K = nums.size();
        for (int i = 0; i < K; i++) {
            if ((i&1) == 0) {
                update_dp(dp1, dp2, 2000, nums[i]);
            } else {
                update_dp(dp2, dp1, 2000, nums[i]);
            }
        }
        if ((K&1) == 1) {
            return dp2[S+1000];
        } else {
            return dp1[S+1000];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 7, 9, 981};
    int ret = s.findTargetSumWays(nums, 1000000000);
    trace(ret);
    return 0;
}
