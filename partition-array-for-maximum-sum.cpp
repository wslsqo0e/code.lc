/*************************************************************************
> File Name:  partition-array-for-maximum-sum.cpp
> Author: shenming
> Created Time: Mon Feb 24 21:55:21 2020
************************************************************************/


#include "common_lc.h"

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N+1);
        if (N == 0) {
            return 0;
        }
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            int cur_max = 0;
            for (int j = i; j>=1 && j >= i+1-K; j--) {
                cur_max = max(cur_max, A[j-1]);
                dp[i] = max(dp[i], dp[j-1] + cur_max *(i-j+1));
            }
        }
        // print_vec<int>(dp);
        return dp[N];
    }
};

int main()
{
    Solution s;
    vector<int> A ={1,15,7,9,2,5,10};
    int ret = s.maxSumAfterPartitioning(A, 3);
    trace(ret);
    return 0;
}
