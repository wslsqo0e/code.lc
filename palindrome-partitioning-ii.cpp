/*************************************************************************
> File Name:  palindrome-partitioning-ii.cpp
> Author: shenming
> Created Time: Tue Feb  4 14:41:22 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    map<pair<int, int>> mm;

    int dp(int i, int j, vector<vector<bool>>& valid) {
        if (valid[i][j]) {
            return 0;
        }
        pair<int, int> key(i, j);
        if (mm.count(key)) {
            return mm[key];
        }
        int c = INT_MAX;
        for (int k = i; k < j; k++) {
            c = min(c, 1+dp(i, k, valid)+dp(k+1, j, valid));
        }
        mm[key] = c;
        return c;
    }

    int minCut(string s) {
        int N = s.size();
        vector<vector<bool>> valid(N, vector<bool>(N, 0));
        for (int l = 1; l <= N; l++) {
            for (int i = 0; i <= N-l; i++) {
                int j = i+l-1;
                if (i == j) {
                    valid[i][j] = 1;
                } else if (i+1 == j) {
                    valid[i][j] = s[i] == s[j];
                } else {
                    valid[i][j] = (s[i] == s[j] && valid[i+1][j-1]);
                }
            }
        }
        return dp(0, N-1, valid);
    }
};

int main()
{
    Solution s;

    return 0;
}
