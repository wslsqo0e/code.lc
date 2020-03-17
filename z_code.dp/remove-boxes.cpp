/*************************************************************************
> File Name:  remove-boxes.cpp
> Author: shenming
> Created Time: Sun Feb  9 14:10:47 2020
************************************************************************/

// https://leetcode.com/problems/remove-boxes/ not done
#include "common_lc.h"

class Solution {
public:
    // merge 成pair  {value, count}
    // dp[i][j] i ~ j 之间的max point
    // dp[i][j] 有两种可能
    // value_i != value_j   dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1]dp[j]) k \in (i, j)
    // value_i == value_j   多了一种可能需要比较
    int removeBoxes(vector<int>& boxes) {
        vector<pair<int, int>> pp;
        int N = boxes.size();
        if (N == 0) {
            return 0;
        }
        pair<int, int> p = {boxes[0], 1};
        for (int i = 1; i < N; i++) {
            if (boxes[i] == boxes[i-1]) {
                p.second += 1;
            } else {
                pp.push_back(p);
                p = {boxes[i], 1};
            }
        }
        pp.push_back(p);
        vector<int> sums;
        sums.push_back(0);
        for (int i = 0; i < pp.size(); i++) {
            sums.push_back(pp[i].second * pp[i].second + sums[sums.size() - 1]);
        }
        N = pp.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N-1; i++) {
            dp[i][i] = pp[i].second * pp[i].second;
            dp[i][i+1] = dp[i][i] + pp[i+1].second * pp[i+1].second;
            // printf("%d %d : %d\n", i, i+1, dp[i][i+1]);
        }
        dp[N-1][N-1] = pp[N-1].second * pp[N-1].second;
        for (int l = 3; l <=N; l++) {
            for (int i = 0, j = i +l -1; j < N; i++, j++) {
                dp[i][j] = sums[j+1] - sums[i];
                if (pp[i].first == pp[j].first) {
                    int sum = 0;
                    int K = pp[i].second;
                    int pre_k = i+1;
                    for (int k = i+2; k <= j; k++) {
                        if (pp[k].first == pp[i].first) {
                            sum += dp[pre_k][k-1];
                            K += pp[k].second;
                            pre_k = k+1;
                            k++;
                        }
                    }
                    sum += K*K;
                    dp[i][j] = max(dp[i][j], sum);
                }
                for (int k = i; k < j; k++) {
                    int sum = dp[i][k] + dp[k+1][j];
                    dp[i][j] = max(sum, dp[i][j]);
                }
                printf("%d %d : %d\n", i, j, dp[i][j]);
            }
        }
        return dp[0][N-1];
    }
};

int main()
{
    Solution s;
    // vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    vector<int> boxes = {1,1, 2, 3, 2, 1, 1};
    // vector<int> boxes = {3, 8, 8, 5, 5, 3, 9, 2, 4, 4, 6, 5, 8, 4, 8, 6, 9, 6, 2, 8, 6, 4, 1, 9, 5, 3, 10, 5, 3, 3, 9, 8, 8, 6, 5, 3, 7, 4, 9, 6, 3, 9, 4, 3, 5, 10, 7, 6, 10, 7};
    int ret = s.removeBoxes(boxes);
    trace(ret);
    return 0;
}
