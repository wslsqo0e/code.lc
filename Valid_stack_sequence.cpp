/*************************************************************************
> File Name:  Valid_stack_sequence.cpp
> Author: shenming
> Created Time: Mon Jan 27 23:45:37 2020
************************************************************************/

#include "common_lc.h"

class Solution {
public:
    // DFS
    bool run(stack<int>&st, vector<int>& pushed, vector<int>& popped) {
        // for (auto i : pushed) {
        //     printf("%d ", i);
        // }
        // printf(" ||| ");
        // for (auto i : popped) {
        //     printf("%d ", i);
        // }
        // printf(" ||| ");
        // stack<int> ss = st;
        // while (ss.size()) {
        //     printf("%d ", ss.top());
        //     ss.pop();
        // }
        // printf("\n");
        if (st.size() == 0 && pushed.size() == 0 && popped.size() == 0) {
            return true;
        }
        if (st.size() > 0 && popped.size() > 0 && st.top() == popped[0]) {
            stack<int> n_st = st;
            vector<int> n_pushed = pushed;
            vector<int> n_popped(popped.begin() + 1, popped.end());
            n_st.pop();
            if (run(n_st, n_pushed, n_popped)) {
                return true;
            }
        }
        if (pushed.size() > 0) {
            stack<int> n_st = st;
            int i = 0;
            for (i = 0; i < pushed.size(); i++) {
                if (pushed[i] != popped[0]) {
                    n_st.push(pushed[i]);
                } else {
                    n_st.push(pushed[i]);
                    vector<int> n_pushed(pushed.begin() + i + 1, pushed.end());
                    vector<int> n_popped(popped.begin(), popped.end());
                    if (run(n_st, n_pushed, n_popped)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        return run(st, pushed, popped);
    }
};

int main()
{
    Solution s;
    vector<int> pushed = {1, 2, 3, 4,5};
    vector<int> popped = {4, 5, 3, 2, 1};
    int ret = s.validateStackSequences(pushed, popped);
    trace(ret);
    return 0;
}
