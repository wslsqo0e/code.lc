/*************************************************************************
> File Name:  unique-binary-search-trees.cpp
> Author: shenming
> Created Time: Sat Feb  8 16:55:21 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[l]  长度为l 的binary search trees的数量
    int numTrees(int n) {
        vector<long long> dp(n+1);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] += dp[i-k] * dp[k-1];
            }
        }
        // print_vec<long long>(dp);
        return dp[n];
    }
};

int main()
{
    Solution s;
    int ret = s.numTrees(3);
    trace(ret);
    return 0;
}
