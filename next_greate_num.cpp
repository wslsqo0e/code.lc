/*************************************************************************
> File Name:  next_greate_num.cpp
> Author: shenming
> Created Time: Fri Jan 24 16:00:53 2020
************************************************************************/
#include "lc_common.h"

class Solution {
public:
    int nextGreaterElement(int n) {
        int num = n;
        std::vector<int> digits;
        while (num) {
            digits.push_back(num%10);
            num /= 10;
        }
        std::reverse(digits.begin(), digits.end());
        std::set<std::pair<int, int>> ss;
        int i = 0;
        int pos = -1;
        for (i = digits.size() - 1; i>=0; i--) {
            pos = -1;
            for (auto s : ss) {
                if (s.first > digits[i]) {
                    pos = s.second;
                    break;
                }
            }
            if (pos != -1) {
                ss.erase(ss.find({digits[pos], pos}));
                int t = digits[pos];
                digits[pos] = digits[i];
                digits[i] = t;
                ss.insert({digits[pos], pos});
                break;
            }
            ss.insert({digits[i], i});
        }
        if (i == -1) {
            return -1;
        }
        for (auto s = ss.begin(); s != ss.end(); s++) {
            i++;
            // printf("%d %d\n", i, s->first);
            digits[i] = s->first;
        }
        long long nn = 0;;
        for (auto i = digits.begin(); i != digits.end(); i++) {
            nn *= 10;
            nn += *i;
        }
        num = nn;
        if (num != nn) {
            return -1;
        }
        return num;
    }
};

int main()
{
    Solution s;
    //int ret = s.nextGreaterElement(230241);
    int ret = s.nextGreaterElement(1999999999);
    printf("%d\n", ret);
    return 0;
}
