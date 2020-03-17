/*************************************************************************
> File Name:  unique-paths.cpp
> Author: shenming
> Created Time: Thu Feb  6 11:00:16 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j] 到达 (i, j) 的方式
    // dp[i][j] = dp[i-1][j] + dp[i][j-1]
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <=n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;

    return 0;
}
