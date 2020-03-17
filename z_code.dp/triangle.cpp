/*************************************************************************
> File Name:  triangle.cpp
> Author: shenming
> Created Time: Wed Feb  5 11:26:14 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        vector<int> dp(N, 0);
        for (int i = 0; i < N; i++) {
            dp[i] = triangle[N-1][i];
        }

        for (int i = N-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution s;

    return 0;
}
