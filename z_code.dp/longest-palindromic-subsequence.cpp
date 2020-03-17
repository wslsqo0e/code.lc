/*************************************************************************
> File Name:  longest-palindromic-subsequence.cpp
> Author: shenming
> Created Time: Tue Feb 11 00:55:46 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j] s[i:j] 最长回文子序列
    // dp[i][j] = 2+dp[i+1][j-1] if s[i] == s[j]
    // else dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N-1; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 2;
            } else {
                dp[i][i+1] = 1;
            }
        }
        dp[N-1][N-1] = 1;
        for (int l = 3; l <= N; l++) {
            for (int i = 0, j = i+l-1; j < N; i++, j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1]+2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                //printf("%d-%d: %d\n", i, j, dp[i][j]);
            }
        }
        return dp[0][N-1];
    }
};

int main()
{
    Solution s;
    int ret = s.longestPalindromeSubseq("abcdef");
    trace(ret);
    return 0;
}
