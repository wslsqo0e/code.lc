/*************************************************************************
> File Name:  minimum-cost-tree-from-leaf-values.cpp
> Author: shenming
> Created Time: Sat Feb  8 13:36:26 2020
************************************************************************/

#include "common_lc.h"

class Solution{
public:
    // dp[i][j]   minimum sum of between [i, j] of arr
    int mctFromLeafValues(vector<int>& arr) {
        int N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N));
        vector<vector<int>> mmax(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            mmax[i][i] = arr[i];
        }

        for (int l = 2; l <= N; l++) {
            printf("l: %d\n", l);
            for (int i = 0; i <= N-l; i++) {
                int j = i + l - 1;
                mmax[i][j] = max(mmax[i][j-1], mmax[j][j]);
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][k] + dp[k+1][j] + mmax[i][k]*mmax[k+1][j], dp[i][j]);
                }
                // printf("\t %d %d %d\n", i, j, dp[i][j]);
            }
        }
        return dp[0][N-1];
    }
};

int main()
{
    Solution s;
    vector<int> arr = {6, 2, 4};
    int ret = s.mctFromLeafValues(arr);
    trace(ret);
    return 0;
}
