/*************************************************************************
> File Name:  video-stitching.cpp
> Author: shenming
> Created Time: Sat Mar  7 20:03:08 2020
************************************************************************/
#include "common_lc.h"

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> TV(T+1);
        for (auto& v: clips) {
            if (v[0] > T) {
                continue;
            }
            TV[v[0]] = max(TV[v[0]], v[1]);
        }

        int end = 0;
        int far_can_reach = 0;
        int count = 0;
        for (int i = 0; end < T; end = far_can_reach) {
            count++;
            while (i < TV.size() && i <= end) {
                far_can_reach = max(TV[i++], far_can_reach);
            }
            if (far_can_reach <= end) {
                return -1;
            }
        }
        return count;


        // int count = 0;
        // int cur = 0;
        // int far_most = TV[cur];
        // count++;
        // while (far_most < T) {
        //     int next_far_most = far_most;
        //     for (int i = cur+1; i <= far_most; i++) {
        //         next_far_most = max(next_far_most, TV[i]);
        //     }
        //     if (next_far_most <= far_most) {
        //         return -1;
        //     }
        //     far_most = next_far_most;
        //     count++;
        // }
        // return count;
    }
};

int main()
{
    Solution s;

    return 0;
}
