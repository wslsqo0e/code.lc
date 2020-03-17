/*************************************************************************
> File Name:  repeat_string_match.cpp
> Author: shenming
> Created Time: Sun Jan 26 23:34:16 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for (int i = 0; i < A.size(); i++) {
            int count = 1;
            if (A[i] == B[0]) {
                int ii = i;
                int j = 1;
                for (j = 1; j < B.size(); j++) {
                    ii++;
                    if (ii >= A.size()) {
                        count++;
                        ii = ii - A.size();
                    }
                    if (A[ii] == B[j]) {
                        continue;
                    } else {
                        break;
                    }
                }
                if (j == B.size()) {
                    return count;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    int ret = s.repeatedStringMatch("aabaa", "aaab");
    trace(ret);
    return 0;
}
