/*************************************************************************
> File Name:  maximum-performance-of-a-team.cpp
> Author: shenming
> Created Time: Tue Mar 17 08:27:15 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // 维持一个k的集合，是结果的最优解
        int modu = pow(10, 9) + 7;
        vector<pair<int, int>> v_p;
        for (int i = 0; i < n; i++) {
            v_p.push_back({efficiency[i], speed[i]});
        }
        std::sort(v_p.begin(), v_p.end());
        std::reverse(v_p.begin(), v_p.end());
        // for (auto p : v_p) {
        //     printf("%d %d\n", p.first, p.second);
        // }
        long long sss = 0;
        int mm = 0;
        priority_queue<int, std::vector<int>, std::greater<int>> speed_pq;
        for (int i = 0; i < n; i++) {
            auto p = v_p[i];
            if (i < k) {
                speed_pq.push(p.second);
                sss += p.second;
                mm = max(mm, (int)sss*p.first %modu);
                // printf("mm: %d\n", mm);
                // printf("sss: %d\n\n", mm);
            } else {
                speed_pq.push(p.second);
                int aa = speed_pq.top(); speed_pq.pop();
                sss = sss + p.second - aa;
                // printf("%d %d %d\n", sss, p.second, aa);
                mm = std::max(mm, (int)(sss*p.first % modu));
                // printf("mm: %d\n", mm);
                // printf("sss: %d\n\n", mm);
            }
        }
        return mm;
    }
};

int main()
{
    Solution s;
    vector<int> speed = {2,8, 2};
    vector<int> efficiency = {2, 7, 1};
    int ret = s.maxPerformance(3, speed, efficiency, 2);
    trace(ret);
    return 0;
}
