/*************************************************************************
> File Name:  longest-palindromic-substring.cpp
> Author: shenming
> Created Time: Tue Feb 11 20:47:16 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][j] s[i:j] is or isn't Palindrome
    string longestPalindrome(string s) {
        int N = s.size();
        if (N == 0) {
            return "";
        }
        vector<vector<bool>> dp(N, vector<bool>(N));
        int max_i = 0;
        int max_j = 0;
        for (int i = 0; i < N-1; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                max_i = i;
                max_j = i+1;
            }
        }
        dp[N-1][N-1] = 1;
        for (int l = 3; l <= N; l++) {
            for (int i = 0, j = i + l -1; j < N; i++, j++) {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    max_i = i;
                    max_j = j;
                }
            }
        }
        return s.substr(max_i, max_j-max_i+1);
    }
};

int main()
{
    Solution s;

    return 0;
}
