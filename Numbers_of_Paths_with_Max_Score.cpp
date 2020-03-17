/*************************************************************************
> File Name:  Numbers_of_Paths_with_Max_Score.cpp
> Author: shenming
> Created Time: Tue Jan 28 10:10:58 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int modu = pow(10, 9) + 7;
    int ctoi(char c) {
        if (c == 'S') {
            return 0;
        }
        return c - '0';
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {0, 0}));
        dp[0][0] = {0, 1};
        for (int i = 1; i < m; i++) {
            if (board[i][0] != 'X' && dp[i-1][0].second) {
                dp[i][0] = {(dp[i-1][0].first + ctoi(board[i][0]))%modu, dp[i-1][0].second};
            } else {
                dp[i][0] = {0, 0};
            }
        }
        for (int j = 1; j < n; j++) {
            if (board[0][j] != 'X' && dp[0][j-1].second) {
                dp[0][j] = {(dp[0][j-1].first + ctoi(board[0][j]))%modu, dp[0][j-1].second};
            }
            for (int i = 1; i < m; i++) {
                if (board[i][j] != 'X') {
                    long long mm = 0;
                    long long mmw = 0;
                    int v = ctoi(board[i][j]);
                    if (dp[i-1][j].second) {
                        if (dp[i-1][j].first + v > mm) {
                            mm = dp[i-1][j].first + v;
                            mmw = dp[i-1][j].second;
                        }
                    }
                    if (dp[i][j-1].second) {
                        if (dp[i][j-1].first + v> mm) {
                            mm = dp[i][j-1].first +v;
                            mmw = dp[i][j-1].second;
                        } else if (dp[i][j-1].first + v == mm) {
                            mmw += dp[i][j-1].second;
                        }
                    }
                    if (dp[i-1][j-1].second) {
                        if (dp[i-1][j-1].first +v> mm) {
                            mm = dp[i-1][j-1].first +v;
                            mmw = dp[i-1][j-1].second;
                        } else if (dp[i-1][j-1].first +v == mm) {
                            mmw += dp[i-1][j-1].second;
                        }
                    }
                    dp[i][j] = {mm%modu, mmw%modu};
                } else {
                    dp[i][j] = {0, 0};
                }
            }
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         printf("%d %d -> ", dp[i][j].first, dp[i][j].second);
        //     }
        //     printf("\n");
        // }
        // return {dp[m-1][n-1].first - 'S', dp[m-1][n-1].second};
        return {(int)(dp[m-1][n-1].first), (int)(dp[m-1][n-1].second)};
    }
};

int main()
{
    Solution s;
    // vector<string> ss = {"E23","2X2","12S"};
    // vector<string> ss= {"E12","1X1","21S"};
    // vector<string> ss = {"E11","XXX","11S"};
    vector<string> ss = {"EX","XS"};
    vector<int> ret = s.pathsWithMaxScore(ss);
    printf("%d %d\n", ret[0], ret[1]);
    return 0;
}
