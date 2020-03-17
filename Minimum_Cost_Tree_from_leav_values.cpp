/*************************************************************************
> File Name:  Minimum_Cost_Tree_from_leav_values.cpp
> Author: shenming
> Created Time: Sun Jan 26 19:22:52 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    map<pair<int, int>, pair<long long, int>> mem;

    pair<long long, int> dp(int be, int en, vector<int>& arr) {
        if (en - be == 1) { // leaf
            return pair<long long, int>(0, arr[be]);
        }
        pair<int, int> key(be, en);
        if (mem.count(key)) {
            return mem[key];
        }
        int second = -1;
        for (int i = be; i < en; i++) {
            if (arr[i] > second) {
                second = arr[i];
            }
        }
        long long mim_first = LONG_MAX;
        for (int i = be + 1; i < en; i++) {
            pair<long long, int> ll = dp(be, i, arr);
            pair<long long, int> rr = dp(i, en, arr);
            long long first = ll.first + rr.first + ll.second * rr.second;
            if (first < mim_first) {
                mim_first = first;
            }
        }
        mem[pair<int, int>(be, en)] = pair<long long, int>(mim_first, second);
        return pair<long long, int>(mim_first, second);
    }

    int mctFromLeafValues(vector<int>& arr) {
        vector<pair<int, int>> pair_arr;
        pair<long long, int> ret = dp(0, arr.size(), arr);
        return (int)ret.first;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {6, 2, 4};
    int ret = s.mctFromLeafValues(nums);
    printf("%d\n", ret);
    return 0;
}
