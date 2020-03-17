/*************************************************************************
> File Name:  buble_switcher_II.cpp
> Author: shenming
> Created Time: Mon Jan 27 11:38:17 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int flipLights(int n, int m) {
        if (n == 0) {
            return 0;
        }
        if (m == 0) {
            return 1;
        }
        if (m %2 == 1) {
            if (m == 1) {
                if (n == 1) {
                    return 2;
                } if (n == 2) {
                    return 3;
                } else {
                    return 4;
                }
            } else {
                if (n == 1) {
                    return 2;
                }
                if (n == 2) {
                    return 4;
                }
                if (n >= 3) {
                    return 8;
                }
            }
        } else {
            if (m == 2) {
                if (n == 1) {
                    return 2;
                }
                if (n == 2) {
                    return 4;
                }
                if (n >= 3) {
                    return 7;
                }
            } else {
                if (n == 1) {
                    return 2;
                }
                if (n == 2) {
                    return 4;
                }
                if (n >= 3) {
                    return 8;
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int ret = s.flipLights(3, 2);
    trace(ret);
    return 0;
}
