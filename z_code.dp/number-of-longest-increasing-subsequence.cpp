/*************************************************************************
> File Name:  number-of-longest-increasing-subsequence.cpp
> Author: shenming
> Created Time: Fri Feb  7 22:13:12 2020
************************************************************************/

#include "common_lc.h"

class Solution{
public:
    // dp[i]  以第i个数结尾的longest increasing-subsequence，长度加种类
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) {
            return 0;
        }
        vector<pair<int, int>> dp(N+1);
        dp[1] = {1, 1};
        for (int i = 2; i <= N; i++) {
            pair<int, int> p = {1, 1};
            for (int j = i-1; j >=1; j--) {
                if (nums[i-1] > nums[j-1]) {
                    if (1 + dp[j].first > p.first) {
                        p.first = 1 + dp[j].first;
                        p.second = dp[j].second;
                    } else if (1 + dp[j].first == p.first) {
                        p.second += dp[j].second;
                    }
                }
            }
            dp[i] = p;
        }
        pair<int, int> p = {0, 1};
        for (int i = N; i >= 1; i--) {
            if (dp[i].first > p.first) {
                p.first = dp[i].first;
                p.second = dp[i].second;
            } else if (dp[i].first == p.first) {
                p.second += dp[i].second;
            }
        }
        return p.second;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 2, 2, 2, 2};
    int ret = s.findNumberOfLIS(nums);
    trace(ret);
    return 0;
}
