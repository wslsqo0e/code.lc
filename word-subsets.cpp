/*************************************************************************
> File Name:  word-subsets.cpp
> Author: shenming
> Created Time: Sat Feb 15 23:07:16 2020
************************************************************************/

#include "common_lc.h"

class cc{
public:
    int count[26];
    cc() {
        memset(count, 0, sizeof(count));
    }
    cc operator += (const cc& other) {
        for (int i = 0; i < 26; i++) {
            if (count[i] >= other.count[i]) {
                continue;
            } else {
                count[i] = other.count[i];
            }
        }
        return *this;
    }
};

bool operator< (const cc& c1, const cc& c2) {
    for (int i = 0; i < 26; i++) {
        if (c1.count[i] > c2.count[i]) {
            return false;
        }
    }
    return true;
}


class Solution {
public:

    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int N = B.size();
        cc cc_B;
        for (int i = 0; i < N; i++) {
            cc c;
            for (auto ch : B[i]) {
                c.count[ch-'a']++;
            }
            cc_B += c;
        }
        vector<string> ret;
        for (auto ss : A) {
            cc c;
            for (auto ch: ss) {
                c.count[ch-'a']++;
            }
            if (cc_B < c) {
                ret.push_back(ss);
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;

    return 0;
}
