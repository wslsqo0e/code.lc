/*************************************************************************
> File Name:  house-robber.cpp
> Author: shenming
> Created Time: Tue Feb 11 21:00:39 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) {
            return 0;
        }
        vector<vector<int>> dp(N, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < N; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[N-1][0], dp[N-1][1]);
    }
};

int main()
{
    Solution s;

    return 0;
}
