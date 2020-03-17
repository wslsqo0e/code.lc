/*************************************************************************
> File Name:  palindromic-substrings.cpp
> Author: shenming
> Created Time: Tue Feb 11 00:41:14 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    // dp[i][j] 判断s[i:j] 是否是回文
    // dp[i][j] 可以通过  dp[i+1][j-1]  s[i] == s[j] 来判断
    int countSubstrings(string s) {
        int N = s.size();
        int total = N;
        vector<vector<int>> dp(N+1, vector<int>(N+1));
        for (int i = 0; i < N -1; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                total++;
            }
        }
        dp[N-1][N-1] = 1;
        for (int l = 3; l <= N; l++) {
            for (int i = 0, j = l-1; j < N; i++, j++) {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    total++;
                }
            }
        }
        return total;
    }
};

int main()
{
    Solution s;
    int ret = s.countSubstrings("aaa");
    trace(ret);
    return 0;
}
