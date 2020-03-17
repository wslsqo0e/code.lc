/*************************************************************************
> File Name:  most-profit-assigning-work.cpp
> Author: shenming
> Created Time: Tue Feb  4 10:58:09 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        vector<pair<int, int>> vv;
        int N = difficulty.size();
        for (int i = 0; i < N; i++) {
            vv.push_back({difficulty[i], profit[i]});
        }
        sort(vv.begin(), vv.end());
        int n = 0;
        int best = vv[n].second;
        int total_max = 0;
        for (auto w : worker) {
            while (n < vv.size() && vv[n].first < w) {
                best = max(vv[n], best);
                n++;
            }
            total_max += best;
        }
        return total_max;
    }
};

int main()
{
    Solution s;

    return 0;
}
