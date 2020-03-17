/*************************************************************************
> File Name:  Fruit_into_baskets.cpp
> Author: shenming
> Created Time: Sat Feb  1 18:27:22 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int len = tree.size();
        if (len <= 2) {
            return len;
        }
        int i = -1;
        int j = 0;
        pair<int, int> ba = {-1, -1};
        pair<int, int> index_ba = {-1, -1};
        int max_len = 0;
        int last = -1;
        for (; j < len; j++) {
            if (ba.first == -1) {
                ba.first = tree[j];
                index_ba.first = j;
            } else if (ba.first != tree[j] && ba.second == -1) {
                ba.second = tree[j];
                index_ba.second = j;
            } else if (ba.first == tree[j]) {
                index_ba.first = j;
            } else if (ba.second == tree[j]) {
                index_ba.second = j;
            } else {
                if (last == ba.first) {
                    ba.second = tree[j];
                    i = index_ba.second;
                    index_ba.second = j;
                } else if (last == ba.second) {
                    ba.first = tree[j];
                    i = index_ba.first;
                    index_ba.first = j;
                }
            }
            last = tree[j];
            int ll = j - i;
            // printf("fi: %d  se: %d\t", index_ba.first, index_ba.second);
            // printf("%d | %d, %d\n", ll, i, j);
            max_len = max(max_len, ll);
        }
        // printf("final: %d %d\n", max_len, j-i);
        // max_len = max(max_len, j-i);
        return max_len;
    }
};


int main()
{
    Solution s;
    // vector<int> A = {1, 0, 3, 4, 3};
    vector<int> A = {1, 2, 3, 2, 2};
    int ret = s.totalFruit(A);
    trace(ret);
    return 0;
}
