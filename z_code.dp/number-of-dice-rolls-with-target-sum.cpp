/*************************************************************************
> File Name:  number-of-dice-rolls-with-target-sum.cpp
> Author: shenming
> Created Time: Thu Feb  6 11:07:34 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[p][i]   d个dice点数为总计i的
    // dp[p][i] -- dp[p-1][i-1] + dp[p-1][i-2] + ... + dp[p-1][i-f]
    // 压缩空间
    int modu = pow(10, 9) + 7;
    int numRollsToTarget(int d, int f, int target) {
        if (target > d*f || target <= (d-1) || target == 0) {
            return 0;
        }
        // if (1 <= target && target <= f) {
        //     return 1;
        // }
        vector<long long> dp(d*f+1);
        // print_vec<long long>(dp);
        for (int i = 1; i <=f; i++) {
            dp[i] = 1;
        }
        // print_vec<long long>(dp);
        for (int i = 2; i <= d; i++) {
            for (int j = i*f; j >= i; j--) {
                dp[j] = 0;
                for (int k = 1; k <=f; k++) {
                    if (j-k >= (i-1) && j-k <= (i-1)*f)
                        dp[j] += dp[j-k];
                }
                dp[j] %= modu;
            }
            // print_vec<long long>(dp);
        }
        return dp[target];
    }
};

int main()
{
    Solution s;
    int ret = s.numRollsToTarget(30, 30, 500);
    trace(ret);
    return 0;
}
