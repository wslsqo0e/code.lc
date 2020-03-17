/*************************************************************************
> File Name:  evaluate-reverse-polish-notation.cpp
> Author: shenming
> Created Time: Tue Feb 18 11:25:21 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t =="/") {
                int value2 = st.top(); st.pop();
                int value1 = st.top(); st.pop();
                int res;
                if (t == "+") {
                    res = value1 + value2;
                } else if (t == "-") {
                    res = value1 - value2;
                } else if (t == "*") {
                    res = value1 * value2;
                } else {
                    res = value1/value2;
                }
                st.push(res);
            } else {
                st.push(atoi(t.c_str()));
            }
        }
        return st.top();
    }
};

int main()
{
    Solution s;
    // vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int ret = s.evalRPN(tokens);
    trace(ret);
    return 0;
}
