/*************************************************************************
> File Name:  jump-game-ii.cpp
> Author: shenming
> Created Time: Tue Feb  4 15:15:17 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        int count = 0;
        while (N != 0) {
            for (int i = 0; i < N; i++) {
                if (nums[i] + i >= N-1) {
                    N = i;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    int ret = s.jump(nums);
    trace(ret);
    return 0;
}
