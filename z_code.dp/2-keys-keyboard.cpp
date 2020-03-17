/*************************************************************************
> File Name:  2-keys-keyboard.cpp
> Author: shenming
> Created Time: Tue Feb  4 22:29:47 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        for (int i = 2; i <= n; i++) {
            if (n%i == 0) {
                return minSteps(n/i) + i;
            }
        }
        return n;
    }
};

class Solution_dp {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        for (int i = 2; i < n+1; i++) {
            for (int j = i; j > 1; j--) {
                if(i%j == 0) {
                    dp[i] = min(dp[i], dp[i/j]+j);
                }
            }
        }
        return dp[n];
    }
}

int main()
{
    Solution s;
    int ret = s.minSteps(3);
    trace(ret);
    return 0;
}
