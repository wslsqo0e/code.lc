/*************************************************************************
> File Name:  Domino_and_Tromino_Tiling.cpp
> Author: shenming
> Created Time: Fri Jan 24 08:59:22 2020
************************************************************************/

#include "lc_common.h"
class Solution {
public:
    const long long MOD = pow(10, 9) + 7;
    typedef pair<int, int> kp;

    map<kp, long long> mem;

    long long dp(int N, int k) {
        if (mem.count({N, k})) {
            return mem[{N, k}];
        }
        long long ret;
        if (k == 0) {
            ret = (dp(N-1, 0) + dp(N-2, -1))%MOD + dp(N-2, 1) + dp(N-2, 0);
        }
        if (k == 1) {
            ret = dp(N-1, 0) + dp(N-1, -1);
        }
        if (k == -1) {
            ret = dp(N-1, 0) + dp(N-1, 1);
        }
        ret %= MOD;
        // ret %= (int)(10e9+7);
        mem[{N, k}] = ret;
        return ret;
    }

    int numTilings(int N) {
        mem[{0, 0}] = 1;
        mem[{0, 1}] = 0;
        mem[{0, -1}] = 0;
        mem[{1, 0}] = 1;
        mem[{1, 1}] = 1;
        mem[{1, -1}] = 1;
        return dp(N, 0);

    }
};

class Solution_ref {
private:
    const long long MOD = pow(10, 9) + 7;
public:
    int numTilings(int N) {
        // when there is nothing to cover, can be done in one way
        if(N == 0)
            return 1;
        // dp(i): no. of unique ways of arranging the tiles
        vector<int> dp(N+1, 0);
        dp[0] = dp[1] = 1;
        if(N >= 2)
            dp[2] = 2;
        if(N >= 3)
            dp[3] = 5;

        for(int i = 4; i <= N; i++)
            dp[i] = ((2 * dp[i - 1]) % MOD + dp[i - 3]) % MOD;

        return dp[N];
    }
};

int main()
{
    Solution_ref s_ref;
    Solution s;
    int ret = s.numTilings(30);
    printf("%d\n", ret);
    ret = s_ref.numTilings(30);
    printf("%d\n", ret);
}
