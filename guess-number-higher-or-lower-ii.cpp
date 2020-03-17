/*************************************************************************
> File Name:  guess-number-higher-or-lower-ii.cpp
> Author: shenming
> Created Time: Tue Feb  4 11:55:25 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 2; l <= n; l++) {
            // printf("l = %d\n", l);
            for (int i = 0; i <= n - l; i++) {
                int mm = min(i+1 + dp[i+1][i+l-1], dp[i][i+l-2]+ i+l-1+1);
                for (int j = i+1; j < i+l - 1; j++) {
                    mm = min(mm, j +1 + max(dp[i][j-1], dp[j+1][i+l-1]));
                }
                dp[i][i+l-1] = mm;
                // printf("\t%d %d -> %d\n", i+1, i+l, mm);
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    Solution s;
    int ret = s.getMoneyAmount(10);
    trace(ret);
    return 0;
}
