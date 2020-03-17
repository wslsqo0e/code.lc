/*************************************************************************
> File Name:  minimum-number-of-taps-to-open-to-water-a-garden.cpp
> Author: shenming
> Created Time: Sat Mar  7 15:06:10 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> max_expand(n+1);
        for (int i = 0; i < n+1; i++) {
            int r = ranges[i];
            int left = i-r < 0 ? 0 : i-r;
            int right = i+r > n ? n : i+r;
            max_expand[right] = max(max_expand[right], right - left);
        }

        int last_cur = n;
        int cur = n - max_expand[n];
        int count = 1;
        while (cur > 0) {
            if (last_cur == cur) {
                return -1;
            }
            int max_left = cur;
            for (int i = last_cur - 1; i >= cur; i--) {
                max_left = min(max_left, i - max_expand[i]);
            }
            last_cur = cur;
            cur = max_left;
            count += 1;
        }
        return count;
    }
};

int main()
{
    Solution s;
    // vector<int> ranges = {3,4,1,1,0,0};
    // int ret = s.minTaps(5, ranges);
    // vector<int> ranges = {0, 0, 0, 0};
    // int ret = s.minTaps(3, ranges);
    vector<int> ranges = {1,2,1,0,2,1,0,1};
    int ret = s.minTaps(7, ranges);
    trace(ret);
    return 0;
}
