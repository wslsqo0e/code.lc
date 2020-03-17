/*************************************************************************
> File Name:  minimum-cost-to-make-at-least-one-valid-path-in-a-grid.cpp
> Author: shenming
> Created Time: Thu Mar  5 23:59:02 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int M, N;
    // int minCost(vector<vector<int>>& grid) {
    //     // 01BFS
    //     M = grid.size();
    //     N = grid[0].size();

    //     vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    //     deque<pair<int, int>> dque; // 第一项为 pos  {N*i + j} 第二项为 cost
    //     dque.push_back({0, 0});
    //     unordered_set<int> visited;
    //     while(dque.size() > 0) {
    //         pair<int, int> cur = dque.front(); dque.pop_front();
    //         int i = cur.first / N;
    //         int j = cur.first % N;
    //         if (i == M-1 && j == N-1) {
    //             return cur.second;
    //         }
    //         for (int k = 0; k < 4; k++) {
    //             int next_i = dirs[k].first + i;
    //             int next_j = dirs[k].second+ j;
    //             int pos = next_i * N + next_j;
    //             if (next_i < 0 || next_i >= M || next_j <0 || next_j >=N || visited.count(pos))
    //                 continue;
    //             int cost = grid[i][j]-1 == k ? 0 : 1;
    //             if (cost == 0 ) {
    //                 dque.push_front({pos, cur.second + cost});
    //             } else {
    //                 dque.push_back({pos, cur.second + cost});
    //             }
    //         }
    //         visited.insert(cur.first);
    //     }
    //     return 0;
    // }
    struct greater_pair {
        bool operator() (pair<int, int>& v1, pair<int, int>& v2) {
            if (v1.first < v2.first) {
                return false;
            }
            if (v1.second < v2.second) {
                return false;
            }
            return true;
        }
    };

    // 基于优先队列的实现
    int minCost(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater_pair> pq; // 第一项为 cost  第二项为 pos
        pq.push({0, 0});
        unordered_set<int> visited;
        while (pq.size() > 0) {
            pair<int, int> cur = pq.top(); pq.pop();
            if (visited.count(cur.second)) {
                continue;
            }
            int i = cur.second / N;
            int j = cur.second % N;
            // printf("(%d, %d), %d\n", i, j, cur.first);
            if (i == M-1 && j == N-1) {
                return cur.first;
            }
            for (int k = 0; k < 4; k++) {
                int next_i = dirs[k].first + i;
                int next_j = dirs[k].second+ j;
                int pos = next_i * N + next_j;
                if (next_i < 0 || next_i >= M || next_j <0 || next_j >=N || visited.count(pos))
                    continue;
                int cost = grid[i][j]-1 == k ? 0 : 1;
                pq.push({cost + cur.first, pos});
            }
            visited.insert(cur.second);
        }
        return 0;
    }
};


int main()
{
    Solution s;
    // vector<vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    vector<vector<int>> grid = {{3,4,3},{2,2,2},{2,1,1},{4,3,2},{2,1,4},{2,4,1},{3,3,3},{1,4,2},{2,2,1},{2,1,1},{3,3,1},{4,1,4},{2,1,4},{3,2,2},{3,3,1},{4,4,1},{1,2,2},{1,1,1},{1,3,4},{1,2,1},{2,2,4},{2,1,3},{1,2,1},{4,3,2},{3,3,4},{2,2,1},{3,4,3},{4,2,3},{4,4,4}};
    int ret = s.minCost(grid);
    trace(ret);
    return 0;
}
