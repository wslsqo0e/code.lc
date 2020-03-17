/*************************************************************************
> File Name:  ones-and-zeroes.cpp
> Author: shenming
> Created Time: Wed Feb  5 11:33:53 2020
************************************************************************/
// https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns
// not done!
#include "common_lc.h"

// time limit exceeded
class Solution1 {
public:
    pair<int, int> get_count(string s) {
        pair<int, int> ret;
        for (auto c : s) {
            if (c == '0') {
                ret.first++;
            } else {
                ret.second++;
            }
        }
        return ret;
    }
    map<pair<int, pair<int, int>>, int> mm;
    int dp(vector<pair<int, int>>& vv, int start, int m, int n) {
        int N = vv.size();
        if (N == start) {
            return 0;
        }
        pair<int, pair<int, int>> key = {start, {m, n}};
        if (mm.count(key)) {
            return mm[key];
        }
        pair<int, int> v = vv[start];
        if (v.first > m || v.second > n) {
            mm[key] = dp(vv, start+1, m, n);
            return mm[key];
        } else {
            int r1 = dp(vv, start+1, m, n);
            int r2 = dp(vv, start+1, m-v.first, n-v.second) + 1;
            mm[key] = max(r1, r2);
            return max(r1, r2);
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> vv;
        for (auto s : strs) {
            vv.push_back(get_count(s));
        }
        return dp(vv, 0, m, n);
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> vv;
        for (auto s : strs) {
            vv.push_back(get_count(s));
        }
        return dp(vv, 0, m, n);
    }
};

int main()
{
    Solution s;

    return 0;
}
