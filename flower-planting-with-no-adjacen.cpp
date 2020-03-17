/*************************************************************************
> File Name:  flower-planting-with-no-adjacen.cpp
> Author: shenming
> Created Time: Mon Feb 24 21:41:43 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> trace;
        for (auto &v : paths) {
            trace[v[0]].push_back(v[1]);
            trace[v[1]].push_back(v[0]);
        }
        vector<int> ret(N);
        for (int i = 1; i <= N; i++) {
            if (trace.count(i) == 0) {
                ret[i-1] = 1;
            }
            set<int> flowers = {1, 2, 3, 4};
            for (auto t : trace[i]) {
                if (flowers.count(ret[t-1])) {
                    flowers.erase(ret[t-1]);
                    // printf("erase, %d\n", ret[t-1]);
                }
            }
            ret[i-1] = *(flowers.begin());
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int N = 4;
    vector<vector<int>> paths = {{1, 2}, {3, 4}};
    vector<int> ret = s.gardenNoAdj(N, paths);
    print_vec<int>(ret);
    return 0;
}
