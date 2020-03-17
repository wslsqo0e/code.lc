/*************************************************************************
> File Name:  longest-common-subsequence.cpp
> Author: shenming
> Created Time: Tue Feb 11 00:25:36 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j]   text1 第 i 个字符   text2 第 j 个字符 时的 Longest Common Subsequence 长度
    // dp[i][j] = dp[i-1][j-1] + 1  if text1[i] == text2[j]
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    int longestCommonSubsequence(string text1, string text2) {
        int M = text1.size();
        int N = text2.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                // printf("%d - %d: %d\n", i, j, dp[i][j]);
            }
        }
        return dp[M][N];
    }
};

int main()
{
    Solution s;
    int ret = s.longestCommonSubsequence("abc", "def");
    trace(ret);
    return 0;
}
