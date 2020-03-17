/*************************************************************************
> File Name:  Kth_Smallest_element_in_a_sorted_matrix.cpp
> Author: shenming
> Created Time: Fri Jan 31 12:25:33 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int i = 1;
        for (; i<=n; i++) {
            if (k > i) {
                k -= i;
            } else {
                break;
            }
        }
        vector<int> vv;
        if (i == n+1) {
            i = n-1;
            for (; i>=1; i--) {
                if (k > i) {
                    k -= i;
                } else {
                    break;
                }
            }
            for (int j = 0;  j < i; j++) {
                vv.push_back(matrix[n - 1 -j][n - i + j]);
            }
        } else {
            for (int j = 0;  j < i; j++) {
                vv.push_back(matrix[j][i-j-1]);
            }
        }


        sort(vv.begin(), vv.end());
        return vv[k-1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int ret = s.kthSmallest(matrix, 8);
    trace(ret);
    return 0;
}
