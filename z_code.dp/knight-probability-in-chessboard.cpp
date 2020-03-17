/*************************************************************************
> File Name:  knight-probability-in-chessboard.cpp
> Author: shenming
> Created Time: Thu Feb  6 12:13:11 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    void update_dp(vector<vector<double>>& dp1, vector<vector<double>>& dp2, int N) {
        vector<pair<int, int>> gap = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp2[i][j] = 0.;
                for (auto p : gap) {
                    if (p.first+i < N && p.first+i >=0 && p.second+j < N && p.second+j >= 0) {
                        dp2[i][j] += 1./8*dp1[i+p.first][j+p.second];
                    }
                }
            }
        }
    }

    // dp[k][i][j] 从(i, j)出发  k 次move 停留在board上的概率
    // dp[k+1][i][j] = sum(1/8*dp[k][.][.] + ...)
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp1(N, vector<double>(N, 1));
        vector<vector<double>> dp2(N, vector<double>(N, 1));

        for (int i = 1; i <= K; i++) {
            if ((i&1) == 1) {
                update_dp(dp1, dp2, N);
            } else {
                update_dp(dp2, dp1, N);
            }
        }
        if ((K&1) == 1) {
            return dp2[r][c];
        } else {
            return dp1[r][c];
        }
    }
};

int main()
{
    Solution s;
    double ret = s.knightProbability(3, 2, 0, 0);
    trace(ret);
    return 0;
}
