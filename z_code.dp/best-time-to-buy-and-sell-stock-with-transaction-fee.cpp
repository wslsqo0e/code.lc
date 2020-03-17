/*************************************************************************
> File Name:  best-time-to-buy-and-sell-stock-with-transaction-fee.cpp
> Author: shenming
> Created Time: Tue Feb 11 21:32:23 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        if (N == 0) {
            return 0;
        }
        int total = 0;
        int cur_min = prices[0];
        int cur_max = prices[0];
        for (int i = 1; i < N; i++) {
            printf("%d %d %d\n", i, cur_min, cur_max);
            if (prices[i] >= prices[i-1]) {
                cur_max = max(prices[i], cur_max);
            } else {
                if (cur_max < cur_min + fee) {
                    if (prices[i] < cur_min) {
                        cur_min = prices[i];
                        cur_max = prices[i];
                    }
                } else {
                    if (prices[i] <= cur_max - fee) {
                        total += (cur_max - cur_min - fee);
                        cur_min = prices[i];
                        cur_max = prices[i];
                    }
                }
            }
        }
        if (cur_max > cur_min + fee) {
            total += (cur_max - cur_min - fee);
        }
        return total;
    }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int N = prices.size();
    //     vector<int> dp(N+1);
    //     for (int i = 2; i <= N; i++) {
    //         dp[i] = max(prices[i-1] - prices[0] - fee, dp[i-1]);
    //         for (int k = 2; k < i; k++) {
    //             if (prices[i-1] > prices[k-1]) {
    //                 dp[i] = max(dp[i], dp[k-1]+prices[i-1]-prices[k-1]-fee);
    //             }
    //         }
    //     }
    //     print_vec<int>(dp);
    //     return dp[N];
    // }
};

// 1  5  2 8  4  9
// 0 3 -1 6 -4 5

int main()
{
    Solution s;
    // vector<int> prices = {1, 3, 2, 8, 4, 9};
    vector<int> prices = {2, 2, 1, 1, 5, 5, 3, 1, 5, 4};
    int ret = s.maxProfit(prices, 2);
    trace(ret);
    return 0;
}
