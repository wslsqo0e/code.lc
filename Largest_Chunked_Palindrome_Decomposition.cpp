/*************************************************************************
> File Name:  Largest_Chunked_Palindrome_Decomposition.cpp
> Author: shenming
> Created Time: Fri Jan 24 23:17:39 2020
************************************************************************/

#include "lc_common.h"

class Solution {
public:
    std::map<string, int> mem;

    int dp(string text) {
        if (text.size() ==  0) {
            return 0;
        }
        if (text.size() == 1) {
            return 1;
        }
        if (mem.count(text)) {
            return mem[text];
        }
        int b = 0;
        int e = text.size() - 1;
        string pre;
        string suf;
        int larget = 1; // itself
        while (b < e) {
            pre += text[b];
            suf = text[e] + suf;
            if (pre == suf) {
                int extra = dp(text.substr(b+1, e-b-1));
                if (2+extra > larget) {
                    larget = 2+extra;
                }
            }
            b++;
            e--;
        }
        mem[text] = larget;
        return larget;
    }
    int longestDecomposition(string text) {
        return dp(text);
    }
};

int main()
{
    Solution s;
    // int ret = s.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi");
    // int ret = s.longestDecomposition("merchant");
    // int ret = s.longestDecomposition("antaprezatepzapreanta");
    int ret = s.longestDecomposition("aaa");
    printf("%d\n", ret);
    return 0;
}
