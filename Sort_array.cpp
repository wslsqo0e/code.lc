/*************************************************************************
> File Name:  Sort_array.cpp
> Author: shenming
> Created Time: Wed Jan 29 15:35:52 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    void sort(vector<int>& nums, int be, int en) {
        if (be >= en) {
            return;
        }
        int piviot = nums[be];
        int i = be;
        int j = en;
        while (i <= j) {
            while (i <= en && nums[i] < piviot) {
                i++;
            }
            while (j >= be && nums[j] > piviot) {
                j--;
            }
            cout << i << " "<<j <<endl;
            if (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        sort(nums, be, j);
        sort(nums, i, en);
    }

    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return nums;
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> vv {5, 2, 3, 1};
    vector<int> ret = s.sortArray(vv);
    print_vec<int>(ret);
    return 0;
}
