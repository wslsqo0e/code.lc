/*************************************************************************
> File Name:  multiply-strings.cpp
> Author: shenming
> Created Time: Sat Feb 15 23:25:50 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> v1;
        vector<int> v2;
        for (auto c : num1) {
            v1.push_back(c - '0');
        }
        for (auto c : num2) {
            v2.push_back(c - '0');
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());

        vector<int> ans;
        ans.resize(v1.size()+v2.size());
        for (int i = 0; i < (int)v1.size(); i++) {
            int pre = 0;
            int j = 0;
            for (j = 0; j < (int)v2.size(); j++) {
                int cur = v1[i]*v2[j] + pre + ans[i+j];
                // printf("cur %d*%d + %d + %d %d\n", v1[i], v2[j], pre, ans[i+j], cur);
                ans[i+j] = cur%10;
                pre = cur - ans[i+j];
                pre/=10;
            }
            // printf("pre %d %d\n", pre, j);
            while (pre > 0) {
                int cur = ans[i + j] + pre;
                ans[i+j] = cur%10;
                pre = cur - ans[i+j];
                pre/=10;
                j++;
            }
            // printf("pre %d %d\n", pre, j);
            // print_vec<int>(ans);
        }
        string ret;
        int i = ans.size() - 1;
        while (ans[i] == 0) {
            i--;
            continue;
        }
        // printf("%d\n", i);
        for (; i>=0; i--) {
            ret.push_back(ans[i]+'0');
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string ss = s.multiply("9", "9");
    trace(ss);
    return 0;
}
