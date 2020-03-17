/*************************************************************************
    > File Name:  countSquares.cpp
    > Author: shenming
    > Created Time: Sat Dec  7 15:47:18 2019
************************************************************************/
#include "lc_common.h"
class Solution_ref {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //dp[i][j] means the biggest square with A[i][j] as bottom-right corner.
        int res=0;
        for (int i=0; i<matrix.size(); i++)
            {
                for (int j=0; j<matrix[0].size(); j++)
                    {
                        if (matrix[i][j]&&i&&j)  matrix[i][j]+=min({matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]});
                        res+=matrix[i][j];
                    }
            }
        return res;
    }
};

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> memo;
    int dp(int i, int j, vector<vector<int>>& matrix) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        if (matrix[i][j] != 1) {
            return 0;
        }
        int size = 0;
        if (memo[i][j] != -1) {
        } else {
            int maxRow = 0;
            while (i + maxRow < m && matrix[i + maxRow][j] == 1) {
                maxRow++;
            }
            int maxCol = 0;
            while (j + maxCol < n && matrix[i][j + maxCol] == 1) {
                maxCol++;
            }
            int maxSize = min(maxRow, maxCol);
            memo[i][j] = min(maxSize, dp(i + 1, j + 1, matrix) + 1);
        }
        size = memo[i][j];
        return size;
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        int size = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                size += dp(i, j, matrix);
            }
        }
        return size;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};

    Solution s;
    int ret = s.countSquares(matrix);
    std::cout << ret << std::endl;
    return 0;
}
