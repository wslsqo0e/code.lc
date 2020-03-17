/*************************************************************************
> File Name:  combination-sum-iv.cpp
> Author: shenming
> Created Time: Thu Feb  6 15:54:32 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // nums中的数据可重复使用，并且计顺序
    // dp[j]  和为 j 的所有可能
    // dp[i] =  sum of ((dp[i-n] for n in nums))
    // 使用dp函数更合适，而非dp数组
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }
        if (nums.size() == 0) {
            return 0;
        }
        int N = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i>=num) {
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target-1];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 33, 333};
    int ret = s.combinationSum4(nums, 10000);
    trace(ret);
    return 0;
}
