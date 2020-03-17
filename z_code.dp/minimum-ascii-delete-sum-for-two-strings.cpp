/*************************************************************************
> File Name:  minimum-ascii-delete-sum-for-two-strings.cpp
> Author: shenming
> Created Time: Tue Feb 11 20:26:16 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j] minimumDeleteSum of s[:i] s[:j]
    int minimumDeleteSum(string s1, string s2) {
        int M = s1.size();
        int N = s2.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        for (int i = 1; i <= M; i++) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for (int j = 1; j <= N; j++) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
                // printf("%d %d : %d\n", i, j, dp[i][j]);
            }
        }
        return dp[M][N];
    }
};

int main()
{
    Solution s;
    int ret = s.minimumDeleteSum("delete", "leet");
    trace(ret);
    return 0;
}
