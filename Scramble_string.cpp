/*************************************************************************
> File Name:  Scramble_string.cpp
> Author: shenming
> Created Time: Wed Jan 29 14:52:47 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    bool compare_b_c(int b1[], int b2[], int n = 26) {
        for (int i = 0; i < n; i++) {
            if (b1[i] != b2[i]) {
                return false;
            }
        }
        return true;
    }

    bool isScramble(string s1, string s2) {
        // cout << "s1: " << s1 << " s2:" << s2 << endl;
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1.size() == 0) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        int b1l[26];
        memset(b1l, 0, sizeof(b1l));
        int b1r[26];
        memset(b1r, 0, sizeof(b1r));
        for (auto a : s1) {
            b1r[a-'a'] ++;
        }
        int b2l[26];
        memset(b2l, 0, sizeof(b2l));
        int b2r[26];
        memset(b2r, 0, sizeof(b2r));
        for (auto a : s2) {
            b2r[a-'a']++;
        }
        if (!compare_b_c(b1r, b2r)) {
            return false;
        }
        int len1 = s1.size();
        int len2 = s2.size();

        for (int i = 1; i < len1; i++) {
            b1l[s1[i-1] - 'a']++;
            b1r[s1[i-1] - 'a']--;
            b2l[s2[i-1] - 'a']++;
            b2r[s2[i-1] - 'a']--;

            if (compare_b_c(b1l, b2l) && compare_b_c(b1r, b2r)) { // no change
                string ss1_l = s1.substr(0, i);
                string ss1_r = s1.substr(i);
                string ss2_l = s2.substr(0, i);
                string ss2_r = s2.substr(i);
                if ((ss1_l == ss2_l || isScramble(ss1_l, ss2_l)) &&
                   (ss1_r == ss2_r || isScramble(ss1_r, ss2_r))) {
                    return true;
                }
            }
        }
        b1l[s1[len1 - 1] - 'a']++;
        b1r[s1[len1 - 1] - 'a']--;
        b2l[s2[len1 - 1] - 'a']++;
        b2r[s2[len1 - 1] - 'a']--;

        for (int i = 1; i < len2; i++) {
            b2r[s2[i-1] - 'a']++;
            b2l[s2[i-1] - 'a']--;
            b1r[s1[len1-i] - 'a']++;
            b1l[s1[len1-i] - 'a']--;
            if (compare_b_c(b1l, b2l) && compare_b_c(b1r, b2r)) { // no change
                string ss1_l = s1.substr(0, len1-i);
                string ss1_r = s1.substr(len1-i);
                string ss2_l = s2.substr(0, i);
                string ss2_r = s2.substr(i);
                if ((ss1_l == ss2_r || isScramble(ss1_l, ss2_r)) &&
                   (ss1_r == ss2_l || isScramble(ss1_r, ss2_l))) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    // string s1 = "great";
    // string s2 = "rgeat";
    string s1 = "abcde";
    string s2 = "caebd";
    // int ret = s.isScramble(s1, s2);
    int ret = s.isScramble("a", "a");
    trace(ret);
    return 0;
}
