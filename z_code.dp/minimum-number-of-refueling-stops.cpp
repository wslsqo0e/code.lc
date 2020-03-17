/*************************************************************************
> File Name:  minimum-number-of-refueling-stops.cpp
> Author: shenming
> Created Time: Wed Feb  5 20:40:51 2020
************************************************************************/
#include "common_lc.h"

class Solution_dp {
public:
    // dp[i][j]   经过第i个stations，并且refuel j次 可抵达的最远距离 j <= i
    // dp[i][j] --  max(dp[i-1][j],  dp[i-1][j-1] + stations[i-1][1])
    // 对于第二种情况，stations[i-1][0] <= dp[i-1][j-1]
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int N = stations.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        for (int i = 0; i < N+1; i++) {
            dp[i][0] = startFuel;
        }
        if (startFuel >= target) return 0;

        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <=N; i++) {
                dp[i][j] = dp[i-1][j];
                if (stations[i-1][0] <= dp[i-1][j-1]) {
                    dp[i][j] = max(stations[i-1][1] + dp[i-1][j-1], dp[i][j]);
                }
                if (dp[i][j] >= target) {
                    return j;
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int cur_max = startFuel;
        int max_ref = 0;
        for (auto& s : stations) {
            // printf("%d\n", cur_max);
            if (cur_max >= target) {
                return max_ref;
            }
            if (s[0] <= cur_max) {
                pq.push(s[1]);
            } else {
                if (pq.empty()) {
                    return -1;
                }
                while (s[0] > cur_max && !pq.empty()) {
                    cur_max += pq.top(); pq.pop();
                    max_ref += 1;
                }
                if (s[0] <= cur_max) {
                    pq.push(s[1]);
                }
            }
        }
        while (cur_max < target && !pq.empty()) {
            cur_max += pq.top(); pq.pop();
            max_ref += 1;
        }
        if (cur_max >= target) {
            return max_ref;
        }
        return -1;
    }
};

int main()
{
    Solution_dp s;
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    int ret = s.minRefuelStops(100, 10, stations);
    trace(ret);
    return 0;
}
