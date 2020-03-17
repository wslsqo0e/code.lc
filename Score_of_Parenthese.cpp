/*************************************************************************
> File Name:  Score_of_Parenthese.cpp
> Author: shenming
> Created Time: Sat Feb  1 13:53:30 2020
************************************************************************/

#include "common_lc.h"
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        for (auto s : S) {
            if (s == '(') {
                st.push(-1);
                printf("push -1\n");
            } else {
                int top = st.top(); st.pop();
                printf("pop %d\n", top);
                if (top != -1) {
                    top *= 2;
                    int t = st.top();
                    st.pop();
                    printf("pop %d\n", t);
                } else {
                    top = 1;
                }
                while (!st.empty() && !(st.top() == -1)) {
                    int a = st.top(); st.pop();
                    top += a;
                }
                printf("push %d\n", top);
                st.push(top);
            }
        }
        return st.top();
    }
};

int main()
{
    Solution s;
    int ret = s.scoreOfParentheses("(()(()))");
    trace(ret);
    return 0;
}
