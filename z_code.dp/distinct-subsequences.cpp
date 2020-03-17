/*************************************************************************
> File Name:  distinct-subsequences.cpp
> Author: shenming
> Created Time: Tue Feb 11 17:49:54 2020
************************************************************************/

#include "common_lc.h"

class Solution_ref {
public:
    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
        vector<long> dp(n+1, 0);
        dp[0] = 1;
        long last;

        for(int i=1; i<=m; i++){
            last = dp[0];
            for(int j=1; j<=n; j++){
                last = dp[j] + (s[i-1] == t[j-1]? last: 0);
                swap(last, dp[j]);
            }
            print_vec<long>(dp);
        }
        return dp[n];
    }
};

class Solution {
public:
    // dp[i][j] s[:i] has how many distinct ways to form t[:j]
    int numDistinct(string s, string t) {
        int M = s.size();
        int N = t.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        for (int i = 0; i<=M; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= N; j++) {
            for (int i = j; i <=M; i++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
                // printf("%d %d: %d\n", i, j, dp[i][j]);
            }
        }
        return dp[M][N];
    }
};

int main()
{
    Solution_ref s;
    int ret = s.numDistinct("rabbbit", "rabbit");
    trace(ret);
    return 0;
}
