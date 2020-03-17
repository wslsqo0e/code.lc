/*************************************************************************
> File Name:  Unique_Letter_String.cpp
> Author: shenming
> Created Time: Thu Jan 30 17:45:43 2020
************************************************************************/
#include "common_lc.h"

class Solution {
    const int M = 1000000007;
    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
public:
    // 换个角度看，结果大不同
    int uniqueLetterString(string S) {
        int r = 0, n = S.length();
        a = \'\'
        vector<int> last(26, -1), len(26);
        for (int i = 0; i < n; ++i) {
            const int c = S[i] - 'A';
            const int temp = len[c];
            len[c] = i -last[c];
            printf("add %d times %d\n", temp, len[c]);
            add(r, temp * len[c]);
            last[c] = i;
            print_vec<int>(len);
            print_vec<int>(last);
        }
        for (int i = 0; i < 26; ++i) {
            printf("add %d times %d\n", n - last[i], len[i]);
            add(r, (n - last[i]) * len[i]);
        }
        return r;
    }
};

int main()
{
    Solution s;
    int ret = s.uniqueLetterString("ACZ");
    trace(ret);
    return 0;
}
