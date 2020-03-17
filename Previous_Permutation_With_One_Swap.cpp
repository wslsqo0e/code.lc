/*************************************************************************
> File Name:  Previous_Permutation_With_One_Swap.cpp
> Author: shenming
> Created Time: Wed Jan 29 12:14:35 2020
************************************************************************/

#include "common_lc.h"

int main()
{
    Solution s;
    vector<int>  nums = {3, 1, 2, 2, 4};
    vector<int> nn = s.prevPermOpt1(nums);
    print_vec<int>(nn);
    return 0;
}
