/*************************************************************************
> File Name:  search_in_rotated_array.cpp
> Author: shenming
> Created Time: Fri Jan 24 19:27:18 2020
************************************************************************/

#include "lc_common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int be = 0;
        int en = nums.size() - 1;
        int mid = (be + en) / 2;
        while (be <= en) {
            mid = (be + en) / 2;
            printf("%d, %d, %d, %d\n", be, en, mid, target);
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[mid] < target) {
                if (nums[mid] >= nums[be]) {
                    be = mid + 1;
                    continue;
                } else {
                    if (target == nums[en]) {
                        return en;
                    }
                    if (target < nums[en]) {
                        be = mid + 1;
                    } else {
                        en = mid - 1;
                    }
                    continue;
                }
            } else { // nums[mid] > target
                if (nums[mid] <= nums[en]) {
                    en = mid - 1;
                    continue;
                } else {
                    if (target == nums[be]) {
                        return be;
                    }
                    if (target > nums[be]) {
                        en = mid - 1;
                    } else {
                        be = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 1};
    int ret = s.search(nums, 3);
    // vector<int> nums = {4, 5, 6, 7,8, 1,2,3};
    // int ret = s.search(nums, 8);
    printf("%d\n", ret);
}
