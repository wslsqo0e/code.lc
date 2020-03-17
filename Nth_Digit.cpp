/*************************************************************************
> File Name:  Nth_Digit.cpp
> Author: shenming
> Created Time: Sat Feb  1 12:50:04 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int findNthDigit(int n) {
        vector<long long> tag = {9, 90*2, 900*3, 9000*4, 90000*5, 900000*6, 9000000*7, 90000000*8};
        int i = 0;
        for (i = 0; i < tag.size(); i++) {
            // printf("%d, %lld %d\n", n, tag[i], i);
            if ((ll)n <= tag[i]) {
                break;
            }
            n -= tag[i];
        }
        int c = (n-1)/(i+1) + pow(10, i);
        int r = (n-1)%(i+1);
        // printf("%d, %d, %d, %d\n", n, c, r, i);
        int res = c%((int)pow(10, i+1-r))/((int)pow(10, i-r));
        return res;

    }
};

int main()
{
    Solution s;
    int ret = s.findNthDigit(2147483647);
    trace(ret);
    return 0;
}
