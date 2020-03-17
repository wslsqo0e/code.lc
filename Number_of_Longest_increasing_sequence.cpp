/*************************************************************************
> File Name:  Number_of_Longest_increasing_sequence.cpp
> Author: shenming
> Created Time: Fri Jan 31 18:11:20 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:

    pair<int, int> find_LIS(vector<int>& nums, int start, vector<int>& pre) {
        if (start >= nums.size()) {
            return {1, 0};
        }
        pair<int, int> ret = {1, 0};
        if (pre.size() > 0) {
            if (nums[start] > pre[0]) {
                vector<int> p_pre;
                p_pre.push_back(nums[start]);
                pair<int, int> cur = find_LIS(nums, start+1, p_pre);
                ret = {cur.first, cur.second + 1};
            }
        } else {
            vector<int> p_pre;
            p_pre.push_back(nums[start]);
            pair<int, int> cur = find_LIS(nums, start+1, p_pre);
            // printf("start: %d == %d %d\n", start, cur.first, cur.second);
            ret = {cur.first, cur.second + 1};
        }
        pair<int, int> cur= find_LIS(nums, start+1, pre);
        if (cur.second > ret.second) {
            ret = cur;
        }
        else if (cur.second == ret.second && cur.second != 0) {
            ret.first += cur.first;
        }
        // print_vec<int>(pre);
        // cout << start << endl;
        // printf("[%d %d]\n", ret.first, ret.second);
        return ret;
    }

    int findNumberOfLIS(vector<int>& nums) {
        vector<int> pre;
        pair<int, int> ret = find_LIS(nums, 0, pre);
        return ret.first;
    }
};

int main()
{
    Solution s;
    vector<int> vv= { 1, 2, 5, 4, 7};
    // vector<int> a = {5};
    // pair<int, int> ret = s.find_LIS(vv, 0, a);
    int ret = s.findNumberOfLIS(vv);
    trace(ret);
    return 0;
}
