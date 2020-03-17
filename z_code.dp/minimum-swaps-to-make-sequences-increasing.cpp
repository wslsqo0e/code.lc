/*************************************************************************
> File Name:  minimum-swaps-to-make-sequences-increasing.cpp
> Author: shenming
> Created Time: Fri Feb  7 12:36:01 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // dp[i][2]    当在位置i时，状态0 (维持原样)  状态1 (翻转) 的最小翻转次数
    // dp[i][0] = min(dp[i-1][0], dp[i-1][1])  or  dp[i-1][0] or dp[i-1][1] 视前后的数字大小而定
    // dp[i][1] = 1 +  [min(dp[i-1][0], dp[i-1][1])  or  dp[i-1][0] or dp[i-1][1]] 视前后的数字大小而定
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<vector<int>> dp(N+1, vector<int>(2));
        dp[1][0] = 0;
        dp[1][1] = 1;
        for (int i = 2; i <= N; i++) {
            if (A[i-1] > A[i-2] && A[i-1] > B[i-2] &&
                B[i-1] > A[i-2] && B[i-1] > B[i-2]) {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = 1 + dp[i][0];
            } else if (A[i-1] <= A[i-2] || B[i-1] <= B[i-2]) {
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            } else if (A[i-1] <= B[i-2] || B[i-1] <= A[i-2]) {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            }
            // printf("%d %d\n", dp[i][0], dp[i][1]);
        }
        return min(dp[N][0], dp[N][1]);
    }
};

int main()
{
    Solution s;
    vector<int> A = {1, 3, 5, 4};
    vector<int> B = {1, 2, 3, 7};
    int ret = s.minSwap(A, B);
    trace(ret);
    return 0;
}
