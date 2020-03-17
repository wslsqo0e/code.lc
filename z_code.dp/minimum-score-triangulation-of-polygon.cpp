/*************************************************************************
> File Name:  minimum-score-triangulation-of-polygon.cpp
> Author: shenming
> Created Time: Sun Feb  9 13:59:43 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    // dp[i][j]   A[i] ... A[j] 之间的Minimum Score
    // 以第一个顶点，最后一个顶点，中间任意一个顶点作为初始三角形，候选变为两个更小的子问题
    // dp[i][j] = min(A[i]*A[j]*A[k] + dp[i][k] + dp[k][j])
    int minScoreTriangulation(vector<int>& A) {
        int N = A.size();
        if (N < 3) {
            return 0;
        }
        if (N == 3) {
            return A[0]*A[1]*A[2];
        }

        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N-2; i++) {
            dp[i][i+2] = A[i]*A[i+1]*A[i+2];
        }
        for (int l = 4; l <= N; l++) {
            for (int i = 0; i < N+1-l; i++) {
                dp[i][i+l-1] = INT_MAX;
                for (int k = i+1; k < i+l-1; k++) {
                    dp[i][i+l-1] = min(dp[i][i+l-1], A[i]*A[i+l-1]*A[k] + dp[i][k] + dp[k][i+l-1]);
                }
            }
        }
        return dp[0][N-1];
    }
};

int main()
{
    Solution s;

    return 0;
}
