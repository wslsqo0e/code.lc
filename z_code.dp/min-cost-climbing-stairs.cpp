/*************************************************************************
> File Name:  min-cost-climbing-stairs.cpp
> Author: shenming
> Created Time: Tue Feb  4 20:41:08 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> dp(N+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <= N; ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + (i == N ? 0 : cost[i]);
        }
        return dp[N];
        // if (N == 0) {
        //     return 0;
        // }
        // if (N == 1) {
        //     return cost[0];
        // }
        // dp[N-1] = cost[N-1];
        // dp[N-2] = cost[N-2];
        // for (int i = N-3; i >= 0; i--) {
        //     dp[i] = min(cost[i]+dp[i+1], cost[i]+dp[i+2]);
        // }
        // return min(dp[0], dp[1]);
    }
};

int main()
{
    Solution s;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int ret = s.minCostClimbingStairs(cost);
    trace(ret);
    return 0;
}
