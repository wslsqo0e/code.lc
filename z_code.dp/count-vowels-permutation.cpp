/*************************************************************************
> File Name:  count-vowels-permutation.cpp
> Author: shenming
> Created Time: Sat Feb  8 13:15:55 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int modu = pow(10, 9) + 7;
    // dp[i][j]  长度为i, 第j个字母结尾的字符串总数
    int countVowelPermutation(int n) {
        if (n == 1) {
            return 5;
        }
        vector<vector<long long>> dp(2, vector<long long>(5));
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 1;
        dp[0][4] = 1;

        for (int i = 2; i <= n; i++) {
            dp[1][0] = dp[0][1];
            dp[1][1] = dp[0][0] + dp[0][2];
            dp[1][2] = dp[0][0] + dp[0][1] + dp[0][3] + dp[0][4];
            dp[1][3] = dp[0][2] + dp[0][4];
            dp[1][4] = dp[0][0];
            for (int j = 0; j < 5; j++) {
                dp[1][j] %= modu;
            }
            swap(dp[0], dp[1]);
        }
        long long sum = 0;
        print_vec<long long>(dp[0]);
        for (int j = 0; j < 5; j++) {
            sum += dp[0][j];
        }
        return sum%modu;
    }
};

int main()
{
    Solution s;
    int ret = s.countVowelPermutation(158);
    trace(ret);
    return 0;
}
