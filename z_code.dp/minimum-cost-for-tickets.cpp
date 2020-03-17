/*************************************************************************
> File Name:  minimum-cost-for-tickets.cpp
> Author: shenming
> Created Time: Tue Feb  4 21:33:05 2020
************************************************************************/

#include "common_lc.h"

// 还有更优雅的方式
class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int N = days.size();
        vector<int> dp(N+1);
        int mi = min(costs[0], min(costs[1], costs[2]));
        dp[0] = 0;
        dp[1] = mi;
        for (int i = 2; i < N+1; i++) {
            dp[i] = dp[i-1] + mi;
            int j = i - 1;
            for (; j >= 1; j--) {
                if (days[j-1] + 7 <= days[i-1]) {
                    break;
                }
            }
            if (j >= 0) {
                dp[i] = min(dp[i], dp[j] + min(costs[1], costs[2]));
                // printf("%d i %d j %d -- %d %d\n", dp[i],i, j, days[i], days[j]);
            }
            for (; j >= 1; j--) {
                if (days[j-1] + 30 <= days[i-1]) {
                    break;
                }
            }
            if (j >= 0)
                dp[i] = min(dp[i], dp[j] + costs[2]);
        }
        // print_vec<int>(dp);
        return dp[N];
    }
};

int main()
{
    Solution s;
    vector<int> days = {1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29};
    vector<int> costs = {3, 14, 50};
    int ret = s.mincostTickets(days, costs);
    trace(ret);
    return 0;
}
