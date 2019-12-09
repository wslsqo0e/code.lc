/*************************************************************************
    > File Name:  tictactoe.cpp
    > Author: shenming
    > Created Time: Sat Dec  7 14:48:50 2019
************************************************************************/
#include "lc_common.h"

class Solution {
public:
    bool is_win(vector<int> pos, int value, std::vector<std::vector<int>>& grid)
    {
        int i = pos[0];
        int j = pos[1];
        grid[i][j] = value;
        // for (auto row : grid) {
        //     for (auto v : row) {
        //         printf("%d\t", v);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return true;
        }
        if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            return true;
        }
        if (i == j) {
            if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
                return true;
            }
        }
        if (grid[1][1] != 0 && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            return true;
        }
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        std::vector<std::vector<int>> grid(3, std::vector<int>(3, 0));
        int c = 0;
        for (auto m : moves) {
            c += 1;
            if (c%2 == 1) {
                if (is_win(m, -1, grid)) {
                    return "A";
                }
                continue;
            }
            else {
                if (is_win(m, 1, grid)) {
                    return "B";
                }
                continue;
            }
        }
        if (c == 9) {
            return "Draw";
        }
        return "Pending";
    }
};

int main(int argc, char* argv[])
{
    // vector<vector<int>>moves = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    vector<vector<int>>moves = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
    Solution s;
    std::string ret = s.tictactoe(moves);
    std::cout << ret << std::endl;
    return 0;
}
