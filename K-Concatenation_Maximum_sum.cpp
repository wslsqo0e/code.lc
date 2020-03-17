/*************************************************************************
> File Name:  K-Concatenation_Maximum_sum.cpp
> Author: shenming
> Created Time: Tue Jan 28 00:42:42 2020
************************************************************************/
#include "common_lc.h"
class Solution {
public:
    int modu = pow(10, 9) + 7;
    int max_sub_arr(vector<int>& arr) {
        int max_sum = 0;
        long long sum = 0;
        for (auto a : arr) {
            if (a >= 0) {
                sum += a;
            } else {
                max_sum = max((int)(sum%modu), max_sum);
                if (sum + a < 0) {
                    sum = 0;
                } else {
                    sum = sum + a;
                }
            }
        }
        return max(max_sum, (int)(sum%modu));
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (k == 1) {
            return max_sub_arr(arr);
        }
        vector<int> d_arr(arr.begin(), arr.end());
        d_arr.insert(d_arr.end(), arr.begin(), arr.end());
        if (k == 2) {
            return max_sub_arr(d_arr);
        }
        int one_sum_arr = accumulate(arr.begin(), arr.end(), 0);
        if (one_sum_arr <= 0) {
            return max_sub_arr(d_arr);
        }
        else {
            int mid = ((k - 2) * one_sum_arr)%modu;
            vector<int> n_arr(arr.begin(), arr.end());
            n_arr.push_back(mid);
            n_arr.insert(n_arr.end(), arr.begin(), arr.end());
            return max_sub_arr(n_arr);
        }
    }
};

int main()
{
    Solution s;

    return 0;
}
