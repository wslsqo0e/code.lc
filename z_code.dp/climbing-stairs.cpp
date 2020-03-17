/*************************************************************************
> File Name:  climbing-stairs.cpp
> Author: shenming
> Created Time: Thu Feb  6 10:47:49 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i] 到达阶梯i的方式
    // dp[i] = dp[i-1] + dp[i-2]
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    Solution s;

    return 0;
}
