/*************************************************************************
> File Name:  InterleavingString.cpp
> Author: shenming
> Created Time: Tue Jan 28 08:42:48 2020
************************************************************************/

#include "common_lc.h"

class Solution_ref {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool dp[s1.size()+1][s2.size()+1];
        memset(dp, 0 , sizeof(dp));
        if (s1.size() + s2.size() != s3.size())
            return false;
        if (!s1.size()) return s2 == s3;
        if (!s2.size()) return s1 == s3;

        dp[0][0] = 1;
        for (int j=1;j<=s2.size();j++) {
            if (dp[0][j-1] && s2[j-1] == s3[j-1])
                dp[0][j] = true;
        }
        for (int i = 1; i < s1.size(); i++) {
            if (dp[i-1][0] && s1[i-1] == s3[i-1]) {
                dp[i][0] = true;
            }
            for (int j = 1; j <= s2.size(); j++) {
                if (s2[j-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j-1];
                }
                if (s1[i-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }
    }
}

class Solution {
public:
    struct triple_s {
        string s1;
        string s2;
        string s3;
        triple_s(string ss1, string ss2, string ss3) : s1(ss1), s2(ss2), s3(ss3) {}
    };

    struct triple_compare {
        bool operator() (const triple_s &t1, const triple_s &t2) const {
            if (t1.s1 < t2.s1) {
                return true;
            }
            if (t1.s2 < t2.s2) {
                return true;
            }
            if (t1.s3 < t2.s3) {
                return true;
            }
            return false;
        }
    };

    map<triple_s, bool, triple_compare> mem;

    bool dp(string s1, string s2, string s3) {
        printf("%s %s %s\n", s1.c_str(), s2.c_str(), s3.c_str());
        if (s1.size() == 0) {
            return s2 == s3;
        }
        if (s2.size() == 0) {
            return s1 == s3;
        }
        if (s3.size() == 0) {
            return false;
        }
        triple_s key(s1, s2, s3);
        if (mem.count(key)) {
            return mem[key];
        }
        bool ret = false;
        if (s1[0] == s3[0]) {
            if (dp(s1.substr(1), s2, s3.substr(1))) {
                mem[key] = true;
                return true;
            }
        }
        if (s2[0] == s3[0]) {
            if (dp(s1, s2.substr(1), s3.substr(1))) {
                mem[key] = true;
                return true;
            }
        }
        mem[key] = false;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        return dp(s1, s2, s3);
    }
};

int main()
{
    Solution s;
    // int ret = s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    int ret = s.isInterleave("aabd", "abdc", "aabdabcd");
    trace(ret);
    return 0;
}
