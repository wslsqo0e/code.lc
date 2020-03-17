/*************************************************************************
> File Name:  dice-roll-simulation.cpp
> Author: shenming
> Created Time: Thu Feb  6 18:33:02 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int modu = pow(10, 9) + 7;
    // dp[j][m]   n \in [0, n]  m \in [0, 6) 代表以 m+1 结尾，填充到 j 位置
    // dp[j][m] = sum(dp[j-1][n], n != m) + sum(dp[j-2][n], n != m) ...
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long long>> dp(n+1, vector<long long>(6));
        for (int i = 1; i <= n; i++) {
            for (int m = 0; m < 6; m++) {
                dp[i][m] = 0;
                for (int j = 1; j <= rollMax[m]; j++) {
                    if (i-j == 0) {
                        dp[i][m] += 1;
                        continue;
                    }
                    if (i - j < 0) {
                        continue;
                    }
                    for (int k = 0; k < 6; k++) {
                        if (m == k) {
                            continue;
                        }
                        dp[i][m] += dp[i-j][k];
                    }
                }
                dp[i][m] %= modu;
            }
            print_vec<long long>(dp[i]);
        }
        long long sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += dp[n][i];
        }
        return sum%modu;
    }
};

class Solution_extra {
public:
    int modu = pow(10, 9) + 7;
    int combine(int m, int n) {
        // printf(" (%d %d) = ", m, n);
        int s = 1;
        for (int i = 0; i < n; i++) {
            s *= m--;
        }
        int nn = n;
        for (int i = 0; i < n; i++) {
            s /= nn--;
        }
        // printf("%d\n", s);
        return s;
    }
    // dp[i][j] 经历 i，占用j个位置 可能达到的排列数
    // 总共有 N 个位置排满  C(i, j)  从 i 个位置挑选 j的可能数目
    // dp[i][j] = dp[i-1][j] + dp[i-1][j-1] * C(N-j+1, 1) + dp[i-1][j-2]*C(N-j+2, 2) + ...
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<long long> dp(n+1);
        // vector<vector<long long>> dp(7, vector<long long>(n+1));
        dp[0] = 1;
        for (int i = 1; i <= 6; i++) {
            int t = rollMax[i-1];
            for (int j = n; j >= 1; j--) {
                for (int k = 1; k <= t; k++) {
                    if (j >= k) {
                        dp[j] += dp[j-k] * combine(n-j+k, k);
                    }
                }
                dp[j] %= modu;
            }
            print_vec<long long>(dp);
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    vector<int> rollMax = {1, 1, 1, 1, 1, 1};
    // vector<int> rollMax = {1, 1, 1, 1, 1, 1};
    int ret = s.dieSimulator(3, rollMax);
    trace(ret);
    return 0;
}
