/*************************************************************************
    > File Name:  palindrome_partition_III.cpp
    > Author: shenming
    > Created Time: Sun Dec  8 11:50:22 2019
************************************************************************/

#include "lc_common.h"

class Solution {
public:
    std::vector<std::vector<int>> mem;
    int modi_count(string s) {
        int sum = 0;
        int i = 0;
        while (i < s.size()/2) {
            if (s[i] != s[s.size() - i - 1]) {
                sum++;
            }
            i++;
        }
        return sum;
    }

    int dp(int s, int k, string str) {
        assert(k > 0 && k <= (int)str.size() - s);
        if (k == 1) {
            return modi_count(str.substr(s));
        }
        if (k == (int)str.size() - s) {
            return 0;
        }
        if (mem[s][k] != -1) {
            return mem[s][k];
        }
        int steps = str.size() - s - k + 1;
        int min_c = str.size();
        static int flag = 0;
        for (int i = 1; i <= steps; i++) {
            int cc = modi_count(str.substr(s, i)) + dp(s+i, k -1, str);
            if (cc < min_c) {
                min_c = cc;
            }
        }
        mem[s][k] = min_c;
        return min_c;

    }
    int palindromePartition(string s, int k) {
        mem = vector<vector<int>>(s.size(), vector<int>(k+1, -1));
        return dp(0, k, s);
    }
};

int main(int argc, char * argv[])
{
    std::string str = "abc";
    int k = 2;
    Solution s;
    int ret = s.palindromePartition(str, k);
    printf("%d\n", ret);
    return 0;
}
