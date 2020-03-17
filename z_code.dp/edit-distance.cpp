/*************************************************************************
> File Name:  edit-distance.cpp
> Author: shenming
> Created Time: Tue Feb 11 17:42:06 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j] word[:i] word[:j] 的编辑距离
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        for (int i = 1; i <= M; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= N; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
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
