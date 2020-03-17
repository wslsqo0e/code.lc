/*************************************************************************
> File Name:  maximal-square.cpp
> Author: shenming
> Created Time: Wed Feb  5 14:31:34 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        int max_len = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (matrix[i-1][j-1] - '0') {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    max_len = max(dp[i][j], max_len);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return max_len*max_len;
    }
};

int main()
{
    Solution s;
    return 0;
}
