/*************************************************************************
> File Name:  least-operators-to-express-number.cpp
> Author: shenming
> Created Time: Mon Feb  3 12:36:31 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // 考虑target转化为x进制
    // 2<=x   无需考虑 x==1 的情况
    int leastOpsExpressTarget(int x, int target) {
        if (target == 0 || target == x) {
            return 0;
        }
        if (target < x) {
            return min(2*target - 1, 2*abs(target-x));
        }
        int k = x;
        int count = 0;
        while (k*x < target) {
            count++;
            k = k*x;
        }
        printf("%d\n", k);
        if (k*x == target) {
            return count+1;
        }
        int target1 = target%k;
        int cc = target/k + target/k*count;
        // printf("target: %d cc: %d, x: %d, target1: %d\n", target, cc, x, target1);
        int cc1 = cc + leastOpsExpressTarget(x, target1);
        int target2 = k - target%k;
        if (target/k == x - 1) {
            cc = count+1+1;
        } else {
            cc = target/k+1 + (target/k+1)*count;
        }
        // printf("target: %d cc: %d, x: %d, target2: %d\n", target, cc, x, target2);
        int cc2 = cc+leastOpsExpressTarget(x, target2);
        return min(cc1, cc2);
    }
};

int main()
{
    Solution s;
    int ret = s.leastOpsExpressTarget(3, 55125018);
    trace(ret);
    return 0;
}
