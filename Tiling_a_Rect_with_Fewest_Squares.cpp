/*************************************************************************
> File Name:  Tiling_a_Rect_with_Fewest_Squares.cpp
> Author: shenming
> Created Time: Wed Jan 29 18:56:46 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    map<pair<int, int>, int> mem;
    int tilingRectangle(int n, int m) {
        if (n == m) {
            return 1;
        }
        int a = max(m, n);
        int b = min(m, n);
        for (int i = 1; i <= b; i++) {
        }
    }
};

int main()
{
    Solution s;

    return 0;
}
