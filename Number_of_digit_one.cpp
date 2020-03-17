/*************************************************************************
> File Name:  Number_of_digit_one.cpp
> Author: shenming
> Created Time: Wed Jan 29 18:19:51 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int get_total_d(int k) {
        if (k == 0) {
            return 0;
        }
        if (k == 1) {
            return 1;
        }
        return pow(10, k-1) + 10*get_total_d(k-1);
    }

    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }
        if (n < 9) {
            return 1;
        }
        int k = 9;
        while (n < pow(10, k)) {
            k--;
        }
        int pp = pow(10, k);
        if (n/pp == 1) {
            return get_total_d(k) + 1+n%pp + countDigitOne(n%pp);
        } else {
            return pp + n/pp*get_total_d(k) + countDigitOne(n%pp);
        }
    }
};

int main()
{
    Solution s;
    int ret = s.countDigitOne(100);
    trace(ret);
    return 0;
}
