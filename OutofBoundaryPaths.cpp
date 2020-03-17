/*************************************************************************
> File Name:  OutofBoundaryPaths.cpp
> Author: shenming
> Created Time: Mon Jan 27 13:04:27 2020
************************************************************************/
#include "common_lc.h"

class Solution {
public:
    map<pair<int, pair<int, int>>, long long>  mem;
    long long modu = pow(10, 9) + 7;

    long long dp(int m, int n, int N, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1;
        }
        if (N == 0) {
            return 0;
        }
        int mim = i;
        mim = min(mim, j);
        mim = min(mim, m-1 -i);
        mim = min(mim, n-1 -j);
        if (N <= mim) {
            return 0;
        }
        pair<int, pair<int, int>> key(N, pair<int, int>(i, j));
        if (mem.count(key)) {
            return mem[key];
        }
        // go up
        int ni = i - 1;
        int nj = j;
        long long ways_up = dp(m, n, N-1, ni, nj);
        // go down
        ni = i + 1;
        nj = j;
        long long ways_down = dp(m, n, N-1, ni, nj);
        // go left
        ni = i;
        nj = j - 1;
        long long ways_left = dp(m, n, N-1, ni, nj);
        // go right
        ni = i;
        nj = j + 1;
        long long ways_right = dp(m, n, N-1, ni, nj);
        mem[key] = (ways_up + ways_down + ways_left + ways_right) % modu;
        return mem[key];
    }

    int findPaths(int m, int n, int N, int i, int j) {
        int ret = dp(m, n, N, i, j);
        return ret;
    }
};

int main()
{
    Solution s;
    int ret = s.findPaths(1, 1, 1,1,1);
    trace(ret);
    return 0;
}
