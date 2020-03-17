/*************************************************************************
> File Name:  knight-dialer.cpp
> Author: shenming
> Created Time: Thu Feb  6 17:48:38 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int modu = pow(10, 9) + 7;
    // dp[K][i]  当前落在数字i上，后续可拨的号码总数
    // dp[K][i] = dp[K-1][i_1] + dp[K-1][i_2]...
    int knightDialer(int N) {
        vector<vector<int>> nums = {{4, 6}, {6, 8}, {7, 9}, {8, 4}, {3, 9, 0}, {},
                                  {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        vector<vector<long long>> dp(N+1, vector<long long>(10, 0));
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 10; j++) {
                for (auto& v : nums[j]) {
                    dp[i][j] += dp[i-1][v];
                }
                dp[i][j] %= modu;
            }
        }
        long long sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += dp[N][i];
        }
        return sum%modu;
    }
};

int main()
{
    Solution s;
    int ret = s.knightDialer(3);
    trace(ret);
    return 0;
}
