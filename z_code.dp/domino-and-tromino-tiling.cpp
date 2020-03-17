/*************************************************************************
> File Name:  domino-and-tromino-tiling.cpp
> Author: shenming
> Created Time: Fri Feb  7 12:13:26 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int modu = pow(10, 9) + 7;
    // dp[i][k]  k = 0, 1, 2  长度为N, 铺设分别为 |  |_  |-  的种类是数
    // dp[i][0] = dp[i-2][1] + dp[i-2][2] + dp[i-1][0] +dp[i-2][0]
    // dp[i][1] = dp[i-1][2] + dp[i-1][0]
    // dp[i][2] = dp[i-1][1] + dp[i-1][0]
    int numTilings(int N) {
        vector<vector<long long>> dp(N+1, vector<long long>(3));
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i][0] = dp[i-2][1] + dp[i-2][2] + dp[i-1][0] + dp[i-2][0];
            dp[i][1] = dp[i-1][2] + dp[i-1][0];
            dp[i][2] = dp[i-1][1] + dp[i-1][0];
            dp[i][0] %= modu;
            dp[i][1] %= modu;
            dp[i][2] %= modu;
        }
        return dp[N][0];
    }
};

int main()
{
    Solution s;
    int ret = s.numTilings(100);
    trace(ret);
    return 0;
}
