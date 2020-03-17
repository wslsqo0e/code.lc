/*************************************************************************
> File Name:  best-time-to-buy-and-sell-stock.cpp
> Author: shenming
> Created Time: Tue Feb 11 21:09:40 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N == 0) {
            return 0;
        }
        int cur_max = INT_MIN;
        int cur_min = prices[0];
        int max_profit = 0;
        for (int i = 1; i < N; i++) {
            if (prices[i] < cur_min) {
                if (cur_max > cur_min) {
                    max_profit = max(max_profit, cur_max - cur_min);
                }
                cur_min = prices[i];
                cur_max = INT_MIN;
            } else if (prices[i] > cur_min) {
                if (prices[i] > cur_max) {
                    cur_max = prices[i];
                }
            } else {
                continue;
            }
        }
        if (cur_max > cur_min) {
            max_profit = max(max_profit, cur_max - cur_min);
        }
        return max_profit;
    }
};

int main()
{
    Solution s;

    return 0;
}
