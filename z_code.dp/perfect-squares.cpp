/*************************************************************************
> File Name:  perfect-squares.cpp
> Author: shenming
> Created Time: Wed Feb  5 00:33:09 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int k = 1;
            dp[i] = INT_MAX;
            while (k*k <= i) {
                dp[i] = min(dp[i], dp[i-k*k] + 1);
                k++;
            }
        }
        // print_vec<int>(dp);
        return dp[n];
    }
};

int main()
{
    Solution s;
    int ret = s.numSquares(12);
    trace(ret)
    return 0;
}
