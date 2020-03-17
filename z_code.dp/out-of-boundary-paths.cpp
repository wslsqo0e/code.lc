/*************************************************************************
> File Name:  out-of-boundary-paths.cpp
> Author: shenming
> Created Time: Sat Feb  8 11:09:37 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int modu = pow(10, 9) + 7;
    void accumulate_sum(int i, int j, int m, int n, long long c, long long& sum) {
        if (i == 0) {
            sum += c;
        }
        if (i == m-1) {
            sum += c;
        }
        if (j == 0) {
            sum += c;
        }
        if (j == n - 1) {
            sum += c;
        }
        sum %= modu;
    }

    // dp[k][i][j]   经历k次move，到达pos (i, j)的方式
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) {
            return 0;
        }
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(m, vector<long long>(n)));
        dp[0][i][j] = 1;
        long long sum = 0;
        accumulate_sum(i, j, m, n, dp[0][i][j], sum);
        for (int k = 1; k < N; k++) {
            for (int ii = 0; ii < m; ii++) {
                for (int jj = 0; jj < n; jj++) {
                    dp[k][ii][jj] = 0;
                    if (ii > 0) {
                        dp[k][ii][jj] += dp[k-1][ii-1][jj];
                    }
                    if (ii < m-1) {
                        dp[k][ii][jj] += dp[k-1][ii+1][jj];
                    }
                    if (jj > 0) {
                        dp[k][ii][jj] += dp[k-1][ii][jj-1];
                    }
                    if (jj < n-1) {
                        dp[k][ii][jj] += dp[k-1][ii][jj+1];
                    }
                    dp[k][ii][jj] %= modu;
                    accumulate_sum(ii, jj, m, n, dp[k][ii][jj], sum);
                }
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    int ret = s.findPaths(1, 3, 3, 0, 1);
    trace(ret);
    return 0;
}
