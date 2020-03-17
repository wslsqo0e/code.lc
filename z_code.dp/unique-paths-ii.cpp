/*************************************************************************
> File Name:  unique-paths-ii.cpp
> Author: shenming
> Created Time: Fri Feb  7 22:40:43 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j]  for pos(i, j) 抵达该位置的路径数
    // dp[i][j] = dp[i-1][j] + dp[i][j-1]   注意边界条件和 Obstacle 情况
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        if (M == 0) {
            return 0;
        }
        int N = obstacleGrid[0].size();
        if (N == 0) {
            return 0;
        }

        vector<vector<long long>> dp(M+1, vector<long long>(N+1));
        dp[0][1] = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (!obstacleGrid[i-1][j-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[M][N];
    }
};

int main()
{
    Solution s;

    return 0;
}
