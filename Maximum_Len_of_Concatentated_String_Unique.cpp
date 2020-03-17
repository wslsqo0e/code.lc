/*************************************************************************
> File Name:  Maximum_Len_of_Concatentated_String_Unique.cpp
> Author: shenming
> Created Time: Thu Jan 30 11:01:20 2020
************************************************************************/

#include "common_lc.h"


class Solution {
public:
    map<size_t, int> mem;
    int get_max_len(vector<string>& arr, set<char> sc) {
        if (arr.size() == 0) {
            return 0;
        }

        if (mem.count(arr.size())) {
            return mem[arr.size()];
        }

        // contain no first
        vector<string> new_arr(arr.begin() + 1, arr.end());
        int len1 = get_max_len(new_arr, sc);

        int len2 = 0;
        string s1 = arr[0];
        bool flag = true;
        for (auto c : s1) {
            if (sc.count(c)) {
                flag = false;
                break;
            }
            sc.insert(c);
        }
        if (flag) {
            len2 = s1.size() + get_max_len(new_arr, sc);
        }
        // mem[arr.size()] = max(len1, len2);
        return max(len1, len2);
    }

    int maxLength(vector<string>& arr) {
        set<char> sc;
        return get_max_len(arr, sc);
    }
};

int main()
{
    Solution s;
    vector<string> vv = {"un","iq","ue"};
    // vector<string> vv = {"abcdefghijklmnopqrstuvwxyz"};
    int ret = s.maxLength(vv);
    trace(ret);
    return 0;
}
