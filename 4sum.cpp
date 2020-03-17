/*************************************************************************
> File Name:  4sum.cpp
> Author: shenming
> Created Time: Thu Feb 27 13:48:43 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int be, int en, int target)
    {
        vector<vector<int>> ret;
        while (be < en) {
            if (nums[be] + nums[en] > target) {
                en--;
            } else if (nums[be] + nums[en] < target) {
                be++;
            } else {
                ret.push_back({nums[be], nums[en]});
                be++; en--;
            }
        }
        return ret;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int be, int target) {
        int en = nums.size();
        vector<vector<int>> ret;
        for (int i = be; i < en-2; i++) {
            if (nums[i] *3 > target) {
                break;
            }
            vector<vector<int>> rr = twoSum(nums, i+1, en-1, target - nums[i]);
            if (rr.size() > 0) {
                for (auto &v : rr) {
                    ret.push_back({nums[i], v[0], v[1]});
                }
            }
        }
        return ret;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        set<pair<int, pair<int, int>>> ss;
        for (int i = 0; i < N-3; i++) {
            if (nums[i]*4 > target) {
                break;
            }
            vector<vector<int>> rr = threeSum(nums, i+1, target-nums[i]);
            if (rr.size() > 0) {
                for (auto &v:rr) {
                    if (!ss.count({nums[i], {v[0], v[1]}})) {
                        ret.push_back({nums[i], v[0], v[1], v[2]});
                        ss.insert({nums[i], {v[0], v[1]}});
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ret = s.fourSum(nums, 0);
    for (auto &v : ret) {
        print_vec<int>(v);
    }
    return 0;
}
