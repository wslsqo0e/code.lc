/*************************************************************************
> File Name:  Combination_sum.cpp
> Author: shenming
> Created Time: Wed Jan 29 20:54:25 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    map<int, int> mem;
    int combine_sum(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }
        if (nums.size() == 0 && target > 0) {
            return 0;
        }
        if (mem.count(target)) {
            return mem[target];
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0) {
                count += combine_sum(nums, target - nums[i]);
            }
        }
        mem[target] = count;
        return count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return combine_sum(nums, target);
    }
};

// class Solution {
// public:
//     void comb_sum(vector<int>& candidates, int target, vector<vector<int>>& ret) {
//         ret.clear();
//         if (candidates.size() == 0) {
//             return;
//         }
//         //if (candidates.size() == 1) {
//         //    if (target == candidates[0]) {
//         //        vector<int> vv;
//         //        vv.push_back(target);
//         //        ret.push_back(vv);
//         //        return;
//         //    }
//         //    return;
//         //}
//         vector<vector<int>> rr;
//         vector<int> new_can(candidates.begin() + 1, candidates.end());
//         vector<int> pre;
//         while (target > 0) {
//             // printf("===\n");
//             // print_vec(pre);
//             // print_vec(new_can);
//             // cout << target << endl;
//             // cout << endl;
//             comb_sum(new_can, target, rr);
//             for(auto r : rr) {
//                 r.insert(r.begin(), pre.begin(), pre.end());
//                 ret.push_back(r);
//             }
//
//             pre.push_back(candidates[0]);
//             target -= candidates[0];
//         }
//         if (target == 0) {
//             ret.push_back(pre);
//         }
//     }
//
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> ret;
//         comb_sum(candidates, target, ret);
//         return ret;
//     }
// };

int main()
{
    Solution s;
    vector<int> num = {1, 2, 3};
    int ret = s.combinationSum4(num, 32);
    trace(ret);
    return 0;
}
