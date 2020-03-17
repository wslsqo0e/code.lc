/*************************************************************************
> File Name:  number-of-ways-to-stay-in-the-same-place-after-some-steps.cpp
> Author: shenming
> Created Time: Sat Feb  8 11:36:57 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j] 经历 i steps, 处于位置j的路径数
    // dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]  注意边界条件
    int modu = pow(10, 9) + 7;
    int numWays(int steps, int arrLen) {
        if (arrLen == 1) {
            return 1;
        }
        int N = min(arrLen, steps+1);
        vector<vector<long long>> dp(steps+1, vector<long long>(N));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][0] %= modu;
            dp[i][N-1] = dp[i-1][N-2] + dp[i-1][N-1];
            dp[i][N-1] %= modu;
            for (int j = 1; j < N-1; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= modu;
            }
        }
        return dp[steps][0];
    }
};

int main()
{
    Solution s;
    int ret = s.numWays(4, 2);
    trace(ret);
    return 0;
}
