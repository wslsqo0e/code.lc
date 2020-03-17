/*************************************************************************
> File Name:  minimum-falling-path-sum.cpp
> Author: shenming
> Created Time: Tue Feb  4 21:11:25 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            dp[0][i] = A[0][i];
        }
        if (N == 1) {
            return dp[0][0];
        }
        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + A[i][0];
            dp[i][N-1] = min(dp[i-1][N-1], dp[i-1][N-2]) + A[i][N-1];
            for (int j = 1; j < N-1; j++) {
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1])) + A[i][j];
            }
        }
        int mm = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (mm > dp[N-1][i]) {
                mm = dp[N-1][i];
            }
        }
        return mm;
    }
};

int main()
{
    Solution s;

    return 0;
}
