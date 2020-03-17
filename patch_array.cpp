/*************************************************************************
> File Name:  patch_array.cpp
> Author: shenming
> Created Time: Sun Feb  2 15:04:11 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxReach = 0;
        int ans = 0;
        for(int i = 0; maxReach < n;) {
            printf("maxReach: %d\n", maxReach);
            if(i < nums.size() && nums[i] <= (maxReach + 1)) {
                maxReach = maxReach + nums[i];
                i++;
            }
            else {
                maxReach = maxReach + maxReach + 1;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 10};
    int ret = s.minPatches(nums, 20);
    trace(ret);
    return 0;
}
