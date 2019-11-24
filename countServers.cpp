/*************************************************************************
    > File Name:  countServers.cpp
    > Author: shenming
    > Created Time: Sun Nov 24 22:38:46 2019
************************************************************************/
// https://leetcode.com/contest/weekly-contest-164/problems/count-servers-that-communicate/

#include "lc_common.h"

// 更简洁的方法
class Solution_ref {
public:
    int countServers(vector<vector<int>>& grid)
    {
        vector<int> rows(grid.size(),0),columns(grid[0].size(),0);	//Stores count of servers in rows and colums
        for(int i=0;i<grid.size();i++)						//Fill the count vectors
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j])
                    rows[i]++,columns[j]++;
        int result=0;
        for(int i=0;i<grid.size();i++)			//Traverse the grid to get result count
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]&&(columns[j]>1||rows[i]>1))	//Check if there are any other server except the current one in it's corresponding row or column.
                    result++;
        return result;
    }
};

class Solution {
public:
    set<pair<int, int>> servers;
    int M;
    int N;
    int get_connected(vector<vector<int>>& grid, int i, int j, set<pair<int, int>>& visited) {
        servers.insert({i, j});
        visited.insert({i, j});

        for (int k = 0; k < N; k++) {
            if (grid[i][k] && !visited.count({i, k})) {
                get_connected(grid, i, k, visited);
            }
        }
        for (int l = 0; l < M; l++) {
            if (grid[l][j] && !visited.count({l, j})) {
                get_connected(grid, l, j, visited);
            }
        }
        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();

        int sum = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] && !servers.count({i, j})) {
                    set<pair<int, int>> visited;
                    get_connected(grid, i, j, visited);
                    if (visited.size() >= 2) {
                        sum += visited.size();
                    }
                }
            }
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    // vector<vector<int>> grid = {{1,0},{1,1}};
    vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    int ret  = s.countServers(grid);
    printf("%d\n", ret);
}
