/*************************************************************************
> File Name:  largest-multiple-of-three.cpp
> Author: shenming
> Created Time: Mon Feb 24 15:37:29 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    string max_ss(string a, string b) {
        if (a.size()  != b.size()) {
            return a.size() > b.size() ? a : b;
        }
        return max(a, b);
    }

    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int N = digits.size();
        vector<vector<string>> dp(2, vector<string>(3));
        if (N == 0) {
            return "";
        }
        dp[0][digits[0]%3] = to_string(digits[0]);
        for (int i = 1; i < N; i++) {
            // if (digits[i] == 0) {
            //     continue;
            // }
            int v = digits[i]%3;
            for (int k = 0; k < 3; k++) {
                if (!dp[0][k].empty()) {
                    dp[1][(v+k)%3] = max_ss(to_string(digits[i]) + dp[0][k], dp[0][(v+k)%3]);
                } else {
                    dp[1][(v+k)%3] = dp[0][(v+k)%3];
                }
            }
            if (dp[1][v].empty()) {
                dp[1][v] = to_string(digits[i]);
            }
            print_vec<string>(dp[1]);
            swap(dp[0], dp[1]);
        }
        string ret = dp[0][0];
        if (ret.size() == 0) {
            return ret;
        }
        if (ret[0] == '0') {
            return "0";
        }
        return ret;
    }
};

int main()
{
    Solution s;
    // vector<int> digits = {0, 0, 0, 0, 0, 3};
    vector<int> digits = {1, 1, 1, 2};
    string ret = s.largestMultipleOfThree(digits);
    trace(ret);
    return 0;
}
