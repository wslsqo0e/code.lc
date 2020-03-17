/*************************************************************************
> File Name:  minimum-path-sum.cpp
> Author: shenming
> Created Time: Tue Feb  4 20:50:56 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    dp[i][j] = min(i > 0 ? dp[i-1][j] : INT_MAX,  j>0 ? dp[i][j-1]:INT_MAX) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution s;

    return 0;
}
