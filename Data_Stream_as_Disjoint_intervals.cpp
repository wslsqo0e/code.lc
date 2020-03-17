/*************************************************************************
> File Name:  Data_Stream_as_Disjoint_intervals.cpp
> Author: shenming
> Created Time: Tue Jan 28 22:55:45 2020
************************************************************************/

#include "common_lc.h"

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    set<pair<int, int>> sp;
    SummaryRanges() {
    }

    void addNum(int val) {
        pair<int, int> cur(val, val);
        sp.insert(cur);

        auto cur_iter = sp.find(cur);
        auto begin = sp.begin();
        bool flag = cur_iter > begin;
        return;
        // bool to_delete = false;
        // auto left = sp.end();
        // auto right = sp.end();
        // if (cur_iter > sp.begin()) {
        //     left = cur_iter - 1;
        //     if (left->second >= cur) {
        //         sp.erase(cur_iter);
        //         return;
        //     }
        //     if (left->second == cur - 1) {
        //         left->second += 1;
        //         to_delete = true;
        //     }
        // }
        // if (cur_iter < sp.end()) {
        //     right = cur_iter + 1;
        //     if (right->first == cur + 1) {
        //         if (to_delete) {
        //             right->first = left->first;
        //             sp.erase(left);
        //             sp.erase(cur_iter);
        //             return;
        //         }
        //         right->first = val;
        //         to_delete = true;
        //     }
        // }
        // if (to_delete) {
        //     sp.erase(cur_iter);
        // }
        // return;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for (auto i : sp) {
            vector<int> vv;
            vv.push_back(i.first);
            vv.push_back(i.second);
            ret.push_back(vv);
        }
        return ret;
    }
};

int main()
{
    SummaryRanges s;
    vector<vector<int>> ret;
    s.addNum(1);
    ret = s.getIntervals();
    print_vv<int>(ret);
    return 0;
}
